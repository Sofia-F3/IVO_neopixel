#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 15
#define NUMPIXELS 3
#define BOT1 34

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pixels.setBrightness(25);
  pinMode(BOT1, INPUT);
}
int color = 1;

void loop() {
  if (digitalRead(BOT1) == LOW) {
    pixels.clear();
    color = random(1, 7);
  }
  switch (color) {
    case 1: //rojo
      color = pixels.Color(255, 0, 0);
      break;
    case 2: //verde
      color = pixels.Color(0, 255, 0);
      break;
    case 3: //azul
      color = pixels.Color(0, 0, 255);
      break;
    case 4: //amarillo
      color = pixels.Color(255, 255, 0);
      break;
    case 5: //violeta
      color = pixels.Color(255, 0, 255);
      break;
    case 6: //celeste
      color = pixels.Color(0, 255, 255);
      break;
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, color);
    pixels.show();
  }
}