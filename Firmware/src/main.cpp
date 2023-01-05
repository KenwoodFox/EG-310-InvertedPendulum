/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for EG-310 Pendulum demonstrator
 */

// Libs
#include <Arduino.h>

// Headers
#include "boardPins.h"

void setup()
{
    // Setup serial
    delay(200);
    Serial.begin(115200);
    Serial.println(MOTD);

    // Configure Pins
    pinMode(STAT_LED, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(STEP, OUTPUT);
    pinMode(DIR, OUTPUT);
    pinMode(TFT_RESET, OUTPUT);
    pinMode(TFT_CS, OUTPUT);
    pinMode(TFT_A0, OUTPUT);

    pinMode(ENC_A, INPUT);
    pinMode(ENC_B, INPUT);
    pinMode(PPIN, INPUT);
    pinMode(IPIN, INPUT);
    pinMode(DPIN, INPUT);
    pinMode(STOP_MODE, INPUT);
    pinMode(START, INPUT);
}

void loop()
{
    delay(2000);
}
