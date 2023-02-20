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

    const byte scrWidth = 180;
    const byte scrHeight = 128;

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
};
