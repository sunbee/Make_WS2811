#include <Arduino.h>

#include <FastLED.h>

#define DATA_PIN 3
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDs 60
#define BRIGTNESS 127
#define FRAMES_PER_SECOND 120

CRGB leds[NUM_LEDs];

void setup() {
  // put your setup code here, to run once:
  delay(3000);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDs);
}

void rainbow() {
  fill_rainbow(leds, NUM_LEDs, 0, 255 / NUM_LEDs);
  FastLED.show(); 
  delay(600);
  fill_solid(leds, NUM_LEDs, CRGB::Black);
  FastLED.show();
  delay(150);
}

void fancy() {
  /*
    Use fill_gradient_RGB to color LEDS in leds array from 1 to NUM_LEDs
    with colors from start to end as specified. The color palette may be
    specified with 2 colors or 4 colors.
  */
  fill_gradient_RGB(leds, NUM_LEDs, CRGB::Magenta, CRGB::Yellow);
  FastLED.show();
  delay(600);
  fill_gradient_RGB(leds, NUM_LEDs, CRGB::Red, CRGB::Yellow, CRGB::Green, CRGB::Blue);
  FastLED.show();
  delay(600);

}

void test_run() {
  /* 
    Test by switching LEDs in the strip on/off one by one.
  */
  for (int i=0; i<NUM_LEDs; i++) {
    leds[i] = CHSV(160, 255,128);
    FastLED.show();
    delay(60);
    leds[i] = CHSV(0, 0, 0);
    FastLED.show();
  } 
}

void loop() {
  // put your main code here, to run repeatedly:
  fancy();
  // rainbow();
}