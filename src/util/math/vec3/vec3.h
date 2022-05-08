#pragma once
#include <cmath>
#include <iostream>

class vec3
{
public:
    // Default constructor sets vector to 0.
    vec3() : v{0.0f, 0.0f, 0.0f} {}

    // Constructor to set values to the vector.
    vec3(double x, double y, double z) : v{x, y, z} {}

    // Setters
    inline void setX(double x) { v[0] = x; }
    inline void setY(double y) { v[1] = y; }
    inline void setZ(double z) { v[2] = z; }

    // Getters
    inline double x() const { return v[0]; }
    inline double y() const { return v[1]; }
    inline double z() const { return v[2]; }

    inline double lenSquared() const
    {
        return std::pow(v[0], 2) + std::pow(v[1], 2) + std::pow(v[2], 2);
    }

    inline double len() const
    {
        return std::sqrt(lenSquared());
    }

private:
    double v[3];
};