
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
#include "calibrate.h"

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
    digitalWrite(STAT_LED, HIGH);
    digitalWrite(DIR, HIGH);

    // Done loading
    tft.loading(100);

    // calibrate(encoder);
    Serial.println(F("Done. Encoder is now at "));
    Serial.println(encoder.read());
}

const int MAX_SPEED = 900;
int setpoint = -100;
int pos = 0;
int err = 0;
int divisor = 0;

// For harmonic oscilation
int freq = 1300; // 1/hz
int encMax = 100;
int lastMax = 0;

void updateMotor()
{
    if (abs(err) < 800)
    {
        int delay = map(abs(setpoint), 0, 100, 20000, MAX_SPEED);
        if (setpoint > 0)
        {
            digitalWrite(DIR, HIGH);
            pos++;
        }
        else
        {
            digitalWrite(DIR, LOW);
            pos--;
        }

        digitalWrite(STEP, HIGH);
        delayMicroseconds(350);
        digitalWrite(STEP, LOW);
        delayMicroseconds(delay);
    }
}

bool myDir = true;

bool spinUpDone = false;
void spinUp()
{
    Serial.println(encoder.read());
    if (abs(encoder.read()) < 30 && millis() - lastMax > 400)
    {
        freq = freq * -1;
        Serial.println("Hit apex!");
        lastMax = millis();
        encMax = 0;
    }
    setpoint = freq;

    if (abs(encoder.read()) > 2000)
    {
        spinUpDone = true;
    }
}

void loop()
{
    // Plot table
    // tft.plot(encoder.read() / 100);

    // Draw screen
    // Serial.println("Drawing New Issues");
    // tft.displayIssues();

    // Blink
    // digitalWrite(STAT_LED, HIGH);
    // delay(100);
    // digitalWrite(STAT_LED, LOW);
    // delay(100);

    // -  (pos * 0.01)
    if (spinUpDone)
    {
        err = encoder.read() - (COUNTS_PER_ROTATION / 2);

        // Primitive I
        if (abs(err) < 20)
        {
            err = err * 1.2;
        }

        setpoint = constrain((err * 0.3) * 10, -101, 101);
        setpoint = -setpoint;

        Serial.println(err);
    }
    else
    {
        spinUp();
    }

    // divisor++;
    // if (divisor >= 4)
    // {
    //     divisor = 0;
    //     freq++;
    // }

    updateMotor();
}
