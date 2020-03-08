#define NUM_LEDS 95
#include "FastLED.h"

#define PIN 3
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(50);
  Serial.begin(9600);
}

void loop() {
  FastLED.clear();
  for (int i = 0; i < NUM_LEDS; i++ ) {
    leds[i] = CRGB::White;
    Serial.println(i);
  }
  FastLED.show();
}
