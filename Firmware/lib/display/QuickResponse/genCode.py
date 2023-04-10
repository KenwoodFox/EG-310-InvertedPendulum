# EG-310

# Tool for converting QR codes to c arrays

from PIL import Image
import argparse


# Defs
def burn(pxl):
    if pxl[0] < 255:
        return 0
    return 1


# Args
parser = argparse.ArgumentParser(
    prog="genCode",
    description="Converts QR Codes in PNG form to c structures.",
    epilog="EG-310",
)
parser.add_argument("filename")


# Begin
args = parser.parse_args()

with Image.open(args.filename) as img:
    width, height = img.size
    pixels = img.load()

    print(
        """
// Auto generated using genCode.py.

#include <Arduino.h>

/* Re-Run included script to re-gen
 * python genCode.py issues.png > qrCodes.h
 */ 
"""
    )

    # We ideally want to output
    # 16 bit wide frames (one avr int)
    # To save on space

    name = args.filename.split(".")[0]
    print(f"const uint8_t {name}_code_width = 3;")
    print(f"const uint8_t {name}_code_height = 33;")
    print(f"const int16_t {name}_code[{name}_code_height][{name}_code_width] = ")
    print("    {")

    for x in range(height):
        print("        {", end="")  # Begin new row
        for y in range(width):
            if y % 15 == 0:
                if y == 0:
                    print("0b", end="")  # Start new int every 16
                else:
                    print(", 0b", end="")

            print(burn(pixels[width - 1 - y, x]), end="")
        print("},")

    print("    };")
