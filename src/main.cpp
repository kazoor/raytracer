#include <iostream>
#include "util/math/vec3/vec3.hpp"
#include "util/color/color.hpp"
#include "ray/ray.hpp"

int main()
{
    // Image
    const int ImageWidth = 1920;
    const int ImageHeight = 1080;

    // Render
    std::cout << "P3\n"
              << ImageWidth << ' ' << ImageHeight << "\n255\n";

    for (int j = ImageHeight - 1; j >= 0; --j)
    {
        std::cerr << "\rScans remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < ImageWidth; ++i)
        {
            Color PixelColor(double(i) / (ImageWidth - 1), double(j) / (ImageHeight - 1), 0.25);
            WriteColor(std::cout, PixelColor);
        }
    }
    std::cerr << "\nDone.\n";
}