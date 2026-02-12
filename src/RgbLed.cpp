#include "RgbLed.h"

RgbLed::RgbLed(uint8_t pin, uint8_t numLeds)
    : _strip(numLeds, pin, NEO_GRB + NEO_KHZ800) {}

void RgbLed::begin() {
  _strip.begin();
  _strip.clear();
  _strip.show();
}

void RgbLed::setBrightnessPercent(uint8_t percent) {
  if (percent > 100) percent = 100;

  uint8_t scaled = map(percent, 0, 100, 10, 255);
  _strip.setBrightness(scaled);
  _strip.show();
}

void RgbLed::off() {
  _strip.clear();
  _strip.show();
}

void RgbLed::red()    { setColor(255, 0, 0); }
void RgbLed::green()  { setColor(0, 255, 0); }
void RgbLed::blue()   { setColor(0, 0, 255); }
void RgbLed::purple() { setColor(80, 0, 80); }
void RgbLed::yellow() { setColor(255, 255, 0); }
void RgbLed::aqua()   { setColor(0, 255, 255); }
void RgbLed::orange()   { setColor(255, 165, 0); }

void RgbLed::setColor(uint8_t r, uint8_t g, uint8_t b) {
  _strip.clear();
  _strip.setPixelColor(0, _strip.Color(r, g, b));
  _strip.show();
}
