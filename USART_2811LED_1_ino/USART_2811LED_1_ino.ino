#include "FastLED.h"
#define NUM_LEDS 12
#define DATA_PIN 3
// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8
CRGB leds[NUM_LEDS];
byte values[NUM_LEDS*3];

void setup() {
	Serial.begin(115200);
   	delay(2000);
    
      // Uncomment one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
       FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
      // FastLED.setBrightness(CRGB(255,255,255));
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      //FastLED.addLeds<LPD8806, 9, 10, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      //for(byte i = 0; i<36; i++){
        leds[0] = CRGB::Green; 
        leds[1] = CRGB::Green;
        leds[2] = CRGB::Green;
        leds[3] = CRGB::Green;
        leds[4] = CRGB::Green;
        leds[5] = CRGB::Green;
        leds[6] = CRGB::Green; 
        leds[7] = CRGB::Green;
        leds[8] = CRGB::Green;
        leds[9] = CRGB::Green;
        leds[10] = CRGB::Green;
        leds[11] = CRGB::Green;
        FastLED.show();
        delay(5000);
        //Serial.println("WAIT_DATA");
        leds[0] = CRGB::Black; 
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black;
        leds[5] = CRGB::Black;
        leds[6] = CRGB::Black; 
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
        leds[9] = CRGB::Black;
        leds[10] = CRGB::Black;
        leds[11] = CRGB::Black;
        FastLED.show();
        Serial.println("WAIT_DATA");
      //}
      
}


void WaitForPrefix()
{
  uint8_t first = 0, second = 0;
  while (second != 0x41 || first != 0x42)
  {
    while (!Serial.available());
    second = first;
    first = Serial.read();
  }
}


void loop() {

WaitForPrefix();
  
  for (byte Led = 0; Led<NUM_LEDS*3; Led++) {
        while(!Serial.available());
        values[Led] = Serial.read();
    }  
   for(byte led=0; led<NUM_LEDS; led++){
   leds[led] = CRGB(values[led],values[led+NUM_LEDS],values[led+(NUM_LEDS*2)]); 
   }

   FastLED.show();
   Serial.println("light_out_OK");
   delay(1000);
   
}
