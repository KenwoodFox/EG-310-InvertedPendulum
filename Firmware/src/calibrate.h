// Libs
#include <Arduino.h>
#include <Encoder.h>

// Some constants
#define COUNTS_PER_ROTATION 4096

/**
 * @brief Auto calibration routine.
 *
 * @param enc An encoder to calibrate (sinusoid alpha decay).
 * @return true if uccessfully calibrated,
 * @return false on alibration error.
 */
bool calibrate(Encoder &enc)
{
    Serial.println("Begining Calibration.");
    for (int i = 0; i < 500; i++)
    {
        Serial.println(enc.read());
        delay(20);
    }

    enc.write(COUNTS_PER_ROTATION / 2);
    return true;
}