
/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for EG-310 Pendulum demonstrator
 */

// Libs
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// Adafruit
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

// Pindefs
#include <boardPins.h>

// Instantiate Objects
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void)
{
    Serial.begin(115200);
    Serial.println(MOTD);

    // Initalize our specific TFT Model (Blacktab, Greentab, etc.)
    tft.initR(INITR_BLACKTAB); // Init ST7735S chip, black tab

    // Our enclosure uses a sideways coordinate system, so we must rotate the screen space
    tft.setRotation(3);

    // Fill the screen
    uint16_t time = millis();
    tft.fillScreen(ST77XX_BLACK);

    // Eventually We'll restrict redrawing
    // to specific areas, so lets bound some
    // static text outside those areas for now.
    tft.setCursor(4, 4);
    tft.setTextColor(ST77XX_WHITE);
    tft.print("Greatness Awaits");
    tft.setCursor(4, 128 - 4 - 8);
    tft.setTextColor(ST77XX_WHITE);
    tft.print(REV);

    // // large block of text
    // tft.fillScreen(ST77XX_BLACK);
    // testdrawtext(MOTD, ST77XX_WHITE);
}

void loop()
{
    delay(500);
}
