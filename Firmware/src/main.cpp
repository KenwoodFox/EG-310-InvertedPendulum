/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for EG-310 Pendulum demonstrator
 */

// Libs
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// Headers
#include "boardPins.h"

// Instantiate devices
Adafruit_MPU6050 mpu;

void setup()
{
    // Setup serial
    delay(200);
    Serial.begin(115200);
    Serial.println(MOTD);

    // Setup devices
    if (!mpu.begin())
    {
        while (1)
        {
            delay(10);
            // This would be a good place to flash an error light
        }
    }
    Serial.println("MPU6050 initalized.");

    // Configure devices
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);    // Sets the MPU range
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); // Sets the loop frequency
}

void loop()
{
    delay(2000);

    // Get the values now, this is just for demo, the real device needs to be much faster. So much faster infact we may just need to make our own lib but, we'll see
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
}
