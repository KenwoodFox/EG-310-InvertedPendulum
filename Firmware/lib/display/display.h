/**
 * @file display.h
 * @author Joe (joseph.sedutto@snhu.edu)
 * @brief Data and Prototypes for the adafruit 1.8 inch display with custom methods for EG310 Pendulum
 *
 */

// AVR/System libs
#include "Arduino.h"

// Adafruit
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735

/**
 * @brief Display object used to manipulate the display.
 *
 * @author Joe (joseph.sedutto@snhu.edu)
 */
class Display
{
private:
    Adafruit_ST7735 tft;

    // General
    const byte scrWidth = 180;
    const byte scrHeight = 128;

    // Plotting
    const byte graphMargin = 14;                        // Margin for graphing
    byte plotWriteHeadPos = graphMargin;                // The point the plot write head was last on.
    const int maxValue = (scrHeight / 2) - graphMargin; // Max allowable value to draw on the graph
    int lastY = 0;                                      // The last y pos

    // Just puts the version on the screen
    void printVersion();

public:
    /**
     * @brief Construct a new Display.
     *
     * @param _CS Chip Select or CS pin
     * @param _DC DC or Data/Command pin
     * @param _RST Reset or RST pin
     */
    Display(byte _CS, byte _DC, byte _RST);

    /**
     * @brief Begin the display.
     *
     */
    void begin();

    /**
     * @brief Construct a new loading object
     *
     * @param complete 0 - 100 how complete
     */
    void loading(byte complete);

    /**
     * @brief Draws the header and footer and things for the main plot window
     *
     */
    void beginPlot();

    /**
     * @brief Plot v from top to bottom
     *
     * @param v The value plotted
     * @param scale The scale its plotted on
     */
    void plot(int v, byte scale = 100);
};
