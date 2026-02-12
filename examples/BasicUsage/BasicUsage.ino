/*
  C6SuperMiniRgbLedLibrary - BasicUsage Example

  This example demonstrates basic RGB LED control using the C6SuperMiniRgbLedLibrary.
  It cycles through different colors and brightness levels.

  Hardware:
  - ESP32 C6 Super Mini
  - WS2812B RGB LED connected to GPIO 8

  Dependencies:
  - Adafruit_NeoPixel (automatically installed with library)
*/

#include <RgbLed.h>

// Initialize RGB LED on GPIO 8 with 1 LED
RgbLed statusLed(8, 1);

void setup() {
  // Initialize serial for debugging
  Serial.begin(115200);
  delay(1000);  // Wait for serial connection

  Serial.println("\n\nC6SuperMiniRgbLedLibrary - BasicUsage Example");
  Serial.println("===========================================");

  // Initialize the LED strip
  statusLed.begin();

  // Set initial brightness to 50%
  statusLed.setBrightnessPercent(50);

  Serial.println("LED initialized. Starting color cycle...\n");
}

void loop() {
  // Display each color for 1 second

  Serial.println("Red");
  statusLed.red();
  delay(1000);

  Serial.println("Green");
  statusLed.green();
  delay(1000);

  Serial.println("Blue");
  statusLed.blue();
  delay(1000);

  Serial.println("Purple");
  statusLed.purple();
  delay(1000);

  Serial.println("Yellow");
  statusLed.yellow();
  delay(1000);

  Serial.println("Aqua");
  statusLed.aqua();
  delay(1000);

  Serial.println("Orange");
  statusLed.orange();
  delay(1000);

  Serial.println("Off");
  statusLed.off();
  delay(1000);

  Serial.println("---");
}

/*
  Brightness Control Example:

  To add brightness control, uncomment the code below and upload:

  void loop() {
    // Fade from 0% to 100% brightness
    statusLed.red();

    for (int brightness = 0; brightness <= 100; brightness += 5) {
      statusLed.setBrightnessPercent(brightness);
      Serial.print("Brightness: ");
      Serial.println(brightness);
      delay(50);
    }

    delay(500);  // Pause at full brightness

    // Fade back down
    for (int brightness = 100; brightness >= 0; brightness -= 5) {
      statusLed.setBrightnessPercent(brightness);
      delay(50);
    }
  }
*/
