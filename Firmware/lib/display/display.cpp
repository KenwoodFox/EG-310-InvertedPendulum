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
    printVersion();
}

void Display::printVersion()
{
    tft.setCursor(4, scrHeight - 11);
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

    // Draw decorational Border
    tft.fillRoundRect(8, 12, scrWidth + 4, scrHeight - 24, 8, ST7735_ORANGE);
    tft.fillRect(graphMargin, 14, scrWidth, scrHeight - 28, ST7735_BLACK);

    // Fill in
    tft.setCursor(4, 4);
    tft.setTextColor(ST77XX_WHITE);
    tft.print("P: 0.1, I: 0.1, D: 0.1");
    printVersion();
};

void Display::plot(int v, byte scale)
{
    // Check if its valid to draw here or not
    if (abs(v) < maxValue and plotWriteHeadPos - 24 > graphMargin)
    {

        // Draw the point
        tft.drawLine(plotWriteHeadPos - 24, (scrHeight / 2) + lastY, plotWriteHeadPos - 23, (scrHeight / 2) + v, ST77XX_RED);
    }

    // Advance write head
    plotWriteHeadPos++;
    if (plotWriteHeadPos > scrWidth)
    {
        plotWriteHeadPos = graphMargin;
    }
    else
    {
        // Record lasts
        lastY = v;
    }

    // Erase head follows! (ominus)
    tft.drawLine(plotWriteHeadPos, graphMargin, plotWriteHeadPos, scrHeight - (graphMargin)-1, ST77XX_BLACK);

    // Draw lines
    tft.drawPixel(plotWriteHeadPos, scrHeight / 2, ST7735_ORANGE);
    // if (plotWriteHeadPos % 50 == 0)
    // {
    //     tft.drawLine(plotWriteHeadPos, 15, plotWriteHeadPos, maxValue + (scrHeight / 2), ST7735_YELLOW);
    // }
};

void Display::displayIssues()
{
    tft.setCursor(4, 4);
    tft.setTextColor(ST77XX_WHITE);
    tft.print("Please Report Issues!");

    byte cursorx = 40;
    byte cursory = 40;

    // Memory for our bit
    unsigned long long bit;
    int16_t row;

    for (uint8_t h = 0; h < test_code_height; h++)
    {
        for (uint8_t i = 0; i < test_code_width; i++)
        {
            row = test_code[h][2 - i];

            for (uint8_t rowi = 0; rowi < 15; rowi++)
            {
                tft.drawPixel(cursorx, cursory, row & 1 ? ST77XX_WHITE : ST77XX_BLACK);

                row >>= 1; // Shift
                cursorx++;
            }
        }
        cursorx = 40;
        cursory++;
    }
}
