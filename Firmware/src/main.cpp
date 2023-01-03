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
}

void loop()
{
    delay(2000);
}
