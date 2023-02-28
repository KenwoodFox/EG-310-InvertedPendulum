
/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for EG-310 Pendulum demonstrator
 */

// AVR/System
#include <Arduino.h>
#include <Encoder.h>

// Our libs
#include "display.h"

// Pindefs
#include <boardPins.h>

// Instantiate Objects
Display tft = Display(TFT_CS, TFT_DC, TFT_RST);
Encoder encoder(ENC_A, ENC_B);

void setup(void)
{
    // Configure serial
    Serial.begin(115200);

    // Begin our display
    tft.begin();
    tft.loading(0); // Update the loading bar

    // Do stuff in here

    // Done loading
    tft.loading(100);

    tft.beginPlot();
}

void loop()
{
    // Plot table
    tft.plot(encoder.read() / 100);
    delay(20);
}
