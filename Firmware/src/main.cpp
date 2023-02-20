
/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for EG-310 Pendulum demonstrator
 */

// AVR/System
#include <Arduino.h>

// Our libs
#include "display.h"

// Pindefs
#include <boardPins.h>

// Instantiate Objects
Display tft = Display(TFT_CS, TFT_DC, TFT_RST);

void setup(void)
{
    // Configure serial
    Serial.begin(115200);

    // Begin our display
    tft.begin();
    tft.loading(0); // Update the loading bar

    delay(200);
    tft.loading(10);

    delay(200);
    tft.loading(30);
    delay(100);
    tft.loading(70);
    delay(500);
    tft.loading(95);
    delay(500);
    tft.loading(96);
    delay(500);
    tft.loading(97);
    delay(900);
    tft.loading(100);
}

void loop()
{
    delay(500);
}
