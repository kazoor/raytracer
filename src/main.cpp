#include <iostream>
#include "util/color/color.hpp"
#include "ray/ray.hpp"
#include "util/math/vec3/vec3.hpp"

Color RayColor(const Ray &r)
{
    Vec3 UnitDirection = UnitVector(r.Direction());
    auto t = 0.5 * (UnitDirection.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{
    // Image
    const double AspectRatio = 16.0f / 9.0f;
    const int ImageWidth = 1920;
    const int ImageHeight = static_cast<int>(ImageWidth / AspectRatio);

    // Camera
    double ViewportHeight = 2.0f;
    double ViewportWidth = AspectRatio * ViewportHeight;
    double FocalLength = 1.0f;

    Point3 Origin(0.0f, 0.0f, 0.0f);
    Vec3 Horizontal(ViewportWidth, 0.0f, 0.0f);
    Vec3 Vertical(0.0f, ViewportHeight, 0.0f);
    auto LowerLeftCorner = Origin - Horizontal / 2 - Vertical / 2 - Vec3(0.0f, 0.0f, FocalLength);

    // Render
    std::cout << "P3\n"
              << ImageWidth << ' ' << ImageHeight << "\n255\n";

    for (int j = ImageHeight - 1; j >= 0; --j)
    {
        std::cerr << "\rScans remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < ImageWidth; ++i)
        {
            double u = double(i) / (ImageWidth - 1.0f);
            double v = double(j) / (ImageHeight - 1.0f);

            Ray r(Origin, LowerLeftCorner + u * Horizontal + v * Vertical - Origin);
            Color PixelColor = RayColor(r);
            WriteColor(std::cout, PixelColor);
        }
    }
    std::cerr << "\nDone.\n";
}