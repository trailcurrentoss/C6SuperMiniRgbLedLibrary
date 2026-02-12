# C6SuperMiniRgbLedLibrary

A simple Arduino library for controlling RGB LEDs on ESP32 C6 Super Mini devices using Adafruit NeoPixel.

## Features

- Easy RGB LED control with predefined colors
- Brightness management (percentage-based)
- Support for multiple LED strips
- Built on Adafruit_NeoPixel library
- Optimized for ESP32 C6 Super Mini

## Installation

### PlatformIO

Add to `platformio.ini`:
```ini
lib_deps =
    https://codeberg.org/trailcurrent/C6SuperMiniRgbLedLibrary.git@0.0.1
```

### Arduino IDE

1. Clone this repository to your Arduino libraries folder
2. Restart Arduino IDE
3. Include the library in your sketch: `#include <RgbLed.h>`

## Dependencies

- [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)

## Quick Start

```cpp
#include <RgbLed.h>

// Initialize RGB LED on GPIO 8 with 1 LED
RgbLed statusLed(8, 1);

void setup() {
  statusLed.begin();
  statusLed.setBrightnessPercent(50);  // 50% brightness
}

void loop() {
  statusLed.red();
  delay(1000);

  statusLed.green();
  delay(1000);

  statusLed.blue();
  delay(1000);

  statusLed.off();
  delay(1000);
}
```

## Available Colors

- `red()` - Red
- `green()` - Green
- `blue()` - Blue
- `purple()` - Purple
- `yellow()` - Yellow
- `aqua()` - Aqua
- `orange()` - Orange
- `off()` - Turn off LED

## API Reference

### Constructor

```cpp
RgbLed(uint8_t pin, uint8_t numLeds = 1)
```

**Parameters:**
- `pin`: GPIO pin number connected to LED data line
- `numLeds`: Number of LEDs in strip (default: 1)

### Methods

```cpp
void begin()                          // Initialize LED strip
void setBrightnessPercent(uint8_t)    // Set brightness 0-100%
void off()                            // Turn off LED
void red()                            // Set LED to red
void green()                          // Set LED to green
void blue()                           // Set LED to blue
void purple()                         // Set LED to purple
void yellow()                         // Set LED to yellow
void aqua()                           // Set LED to aqua
void orange()                         // Set LED to orange
```

## Hardware Setup

### ESP32 C6 Super Mini Connections

| Signal | Pin |
|--------|-----|
| LED Data | GPIO 8 (configurable) |
| LED VCC | 3.3V or 5V |
| LED GND | GND |

**Note:** WS2812B LEDs typically require 5V power but work with 3.3V data signals.

## Example Use Cases

### Status Indicator
```cpp
RgbLed statusLed(8, 1);

void indicateStatus(Status status) {
  switch (status) {
    case STATUS_OK:
      statusLed.green();
      break;
    case STATUS_WARNING:
      statusLed.yellow();
      break;
    case STATUS_ERROR:
      statusLed.red();
      break;
  }
}
```

### Brightness Control
```cpp
RgbLed brightnessDimmableLed(8, 1);

void setup() {
  brightnessDimmableLed.begin();
}

void loop() {
  // Fade from 0% to 100% brightness
  for (int i = 0; i <= 100; i += 10) {
    brightnessDimmableLed.green();
    brightnessDimmableLed.setBrightnessPercent(i);
    delay(100);
  }
}
```

## License

MIT License - see LICENSE file for details

## Contributing

Pull requests welcome! Please ensure code follows existing style and conventions.

## Credits

Built on the excellent [Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library.

## Support

For issues, questions, or suggestions, please open an issue on GitHub.
