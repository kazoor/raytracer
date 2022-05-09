#pragma once
#include <cmath>
#include <iostream>

class Vec3
{
public:
    // Constructors
    Vec3() : u{0.0f, 0.0f, 0.0f} {}

    Vec3(double x, double y, double z) : u{x, y, z} {}

    // Setters
    inline void SetX(double x) { u[0] = x; }
    inline void SetY(double y) { u[1] = y; }
    inline void SetZ(double z) { u[2] = z; }

    // Getters
    inline double x() const { return u[0]; }
    inline double y() const { return u[1]; }
    inline double z() const { return u[2]; }

    inline double LengthSquared() const
    {
        return std::pow(u[0], 2) + std::pow(u[1], 2) + std::pow(u[2], 2);
    }

    inline double Length() const
    {
        return std::sqrt(LengthSquared());
    }

    // Operators
    inline double operator[](int i) const { return u[i]; }
    inline double &operator[](int i) { return u[i]; }

    inline Vec3 operator-() const { return Vec3(-u[0], -u[1], u[2]); }

    inline Vec3 &operator+=(const Vec3 &v)
    {
        u[0] += v.u[0];
        u[1] += v.u[1];
        u[2] += v.u[2];

        return *this;
    }

    inline Vec3 &operator*=(const double t)
    {
        u[0] *= t;
        u[1] *= t;
        u[2] *= t;

        return *this;
    }

    Vec3 &operator/=(const double t)
    {
        return *this *= 1 / t;
    }

private:
    double u[3];
};

inline std::ostream &operator<<(std::ostream &out, const Vec3 &v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline Vec3 operator*(double t, Vec3 &u)
{
    return Vec3(t * u.x(), t * u.y(), t * u.z());
}

inline Vec3 operator*(const Vec3 &u, double t)
{
    return u * t;
}

inline Vec3 operator/(Vec3 u, double t)
{
    return (1 / t) * u;
}

inline double Dot(const Vec3 &u, Vec3 &v)
{
    return u.x() * v.x() + u.y() * v.y() + u.y() * v.y();
}

inline Vec3 Cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3(
        u.y() * v.z() - u.z() * v.y(),
        u.z() * v.x() - u.x() * v.z(),
        u.x() * v.y() - u.y() * v.x());
}

inline Vec3 UnitVector(Vec3 u)
{
    return u / u.Length();
}

// Other usages of a Vec3.
using Point3 = Vec3; // 3D point
using Color = Vec3;  // RGB