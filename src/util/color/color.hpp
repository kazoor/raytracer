#pragma once
#include <iostream>
#include "../math/vec3/vec3.hpp"

void WriteColor(std::ostream &Out, Color PixelColor)
{
    Out << static_cast<int>(255.999f * PixelColor.x()) << ' '
        << static_cast<int>(255.999f * PixelColor.y()) << ' '
        << static_cast<int>(255.999f * PixelColor.z()) << '\n';
}