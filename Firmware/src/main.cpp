
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
    for (byte i = 0; i < 30; i++)
    {
        tft.loading(i);
        delay(100);
    }

    // Done loading
    tft.loading(100);
    delay(50);

    tft.beginPlot();
}

void loop()
{
    // Plot table
    tft.plot(sin(millis() / 100) * 40);
    delay(20);
}
