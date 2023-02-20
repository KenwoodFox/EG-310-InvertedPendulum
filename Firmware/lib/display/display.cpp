/**
 * @file display.cpp
 * @author Joe (joseph.sedutto@snhu.edu)
 * @brief methods for the 1.8inch display
 *
 */

#include "display.h"

// AVR/Framework
#include "Arduino.h"
#include <SPI.h>

// Adafruit
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735

Display::Display(byte _CS, byte _DC, byte _RST) : tft(_CS, _DC, _RST)
{
    ;
};

void Display::begin()
{
    // Initalize our specific TFT Model (Blacktab, Greentab, etc.)
    tft.initR(INITR_BLACKTAB); // Init ST7735S chip, black tab

    // Our enclosure uses a sideways coordinate system, so we must rotate the screen space
    tft.setRotation(3);

    // Fill the screen
    tft.fillScreen(ST77XX_BLACK);

    // Eventually We'll restrict redrawing
    // to specific areas, so lets bound some
    // static text outside those areas for now.
    tft.setCursor(4, 4);
    tft.setTextColor(ST77XX_WHITE);
    tft.print("Greatness Awaits");
    tft.setCursor(4, scrHeight - 4 - 8);
    tft.setTextColor(ST77XX_WHITE);
    tft.print(REV);
}

void Display::loading(byte complete)
{
    byte loadHeight = 24;
    byte loadGap = 12;
    byte barLen = scrWidth - (loadGap * 4);

    // Completion dist
    byte cdist = map(complete, 0, 100, 0, 124);

    // Border
    tft.fillRoundRect(loadGap, (scrHeight / 2) - (loadHeight / 2), barLen, loadHeight, 6, ST77XX_ORANGE);

    // Actual loading bar
    tft.fillRoundRect(loadGap + 4 + cdist, (scrHeight / 2) - ((loadHeight - 8) / 2), barLen - 8 - cdist, loadHeight - 8, 6, ST77XX_BLACK);
};

void Display::beginPlot()
{
    // Fill the screen
    tft.fillScreen(ST77XX_BLACK);
};

void Display::plot(int v, byte scale)
{
    // Draw the point
    tft.drawLine(plotWriteHeadPos + 3, (scrHeight / 2) + lastY, plotWriteHeadPos + 4, (scrHeight / 2) + v, ST77XX_RED);
    plotWriteHeadPos++;

    if (plotWriteHeadPos > scrWidth)
    {
        plotWriteHeadPos = 0;
    }
    else
    {
        // Record lasts
        lastY = v;
    }

    // Erase head follows! (ominus)
    tft.drawLine(plotWriteHeadPos + 20, 0, plotWriteHeadPos + 20, scrHeight, ST77XX_BLACK);
};
