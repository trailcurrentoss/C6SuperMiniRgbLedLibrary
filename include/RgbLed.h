#ifndef RGB_LED_HEADER_H
#define RGB_LED_HEADER_H
#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class RgbLed {
public:
  RgbLed(uint8_t pin, uint8_t numLeds = 1);

  void begin();
  void setBrightnessPercent(uint8_t percent);

  void off();
  void red();
  void green();
  void blue();
  void purple();
  void yellow();
  void aqua();
  void orange();

private:
  void setColor(uint8_t r, uint8_t g, uint8_t b);

  Adafruit_NeoPixel _strip;
};

#endif // RGB_LED_HEADER_H