
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

// Pindefs and misc
#include <boardPins.h>

// Instantiate Objects
Display tft = Display(TFT_CS, TFT_DC, TFT_RST);
Encoder encoder(ENC_A, ENC_B);

void setup(void)
{
    // Configure serial
    Serial.begin(115200);
    Serial.println(REV);

    // Begin our display
    tft.begin();
    tft.loading(0); // Update the loading bar

    // Inputs and Outputs
    pinMode(STAT_LED, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(DIR, OUTPUT);
    pinMode(STEP, OUTPUT);
    pinMode(PPIN, INPUT);
    pinMode(IPIN, INPUT);
    pinMode(DPIN, INPUT);

    digitalWrite(ENABLE, HIGH);

    // Done loading
    tft.loading(100);

    // tft.beginPlot();

    // tft.displayIssues();

    delay(2000);
}

void loop()
{

    // Plot table
    // tft.plot(encoder.read() / 100);
    // delay(20);

    // Draw screen
    // Serial.println("Drawing New Issues");
    // tft.displayIssues();

    // Blink
    // digitalWrite(STAT_LED, HIGH);
    // delay(100);
    // digitalWrite(STAT_LED, LOW);
    // delay(100);

    // Test motor
    digitalWrite(ENABLE, LOW); // Enable Motor
    digitalWrite(DIR, LOW);

    digitalWrite(STEP, LOW);
    digitalWrite(STAT_LED, LOW);
    delayMicroseconds(1000);
    digitalWrite(STEP, HIGH);
    digitalWrite(STAT_LED, HIGH);
    delayMicroseconds(1200);

    Serial.println(analogRead(PPIN));
}
