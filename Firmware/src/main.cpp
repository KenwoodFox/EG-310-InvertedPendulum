
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

    // Do stuff in here
    tft.loading(5);
    delay(100);
    tft.loading(90);
    delay(500);

    // Done loading
    tft.loading(100);
    delay(50);

    tft.beginPlot();
}

void loop()
{
    // Plottable
    tft.plot(sin(millis() / 100) * 40);
    delay(20);
}
