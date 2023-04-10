/**
 * @file controls.cpp
 * @author Joe
 *
 * @brief Inputs and Controls
 */

#include <Arduino.h>
#include <boardPins.h>

void beginControls()
{
    ;
}

int getP()
{
    return analogRead(PPIN);
}

int getI()
{
    return analogRead(IPIN);
}

int getD()
{
    return analogRead(DPIN);
}
