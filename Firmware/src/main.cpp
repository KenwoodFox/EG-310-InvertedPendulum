/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for EG-310 Pendulum demonstrator
 */

//  This option forces Encoder.h to use actual assembly code to squeeze extra performance from the system
// #define ENCODER_OPTIMIZE_INTERRUPTS

// Libs
#include <Arduino.h>
// #include <Encoder.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

// Headers
#include "boardPins.h"

// Instantiate objects
// Encoder pendulumEncoder(ENC_A, ENC_B);
Adafruit_ST7735 disp = Adafruit_ST7735(TFT_CS, TFT_A0, TFT_RESET);

float p = 3.1415926; // Delete me later

void setup()
{
    // Setup serial
    delay(200);
    Serial.begin(115200);
    Serial.println(MOTD);

    // Init display
    disp.initR(INITR_GREENTAB);

    // Fill with black
    disp.fillScreen(ST77XX_BLACK);
    delay(500);

    disp.setCursor(0, 0);
    disp.setTextColor(ST7735_WHITE);
    disp.setTextWrap(true);
    disp.print("HelloWorld!");

    disp.drawLine(0, 0, disp.width() - 1, disp.height() - 1, ST7735_YELLOW);
    disp.drawLine(disp.width() - 1, 0, 0, disp.height() - 1, ST7735_YELLOW);

    disp.drawPixel(0, disp.height() / 2, ST7735_GREEN);
}

void loop()
{
    delay(500);
}
