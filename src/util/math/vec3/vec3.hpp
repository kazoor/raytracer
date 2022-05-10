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
    void SetX(double x) { u[0] = x; }
    void SetY(double y) { u[1] = y; }
    void SetZ(double z) { u[2] = z; }

    // Getters
    double x() const { return u[0]; }
    double y() const { return u[1]; }
    double z() const { return u[2]; }

    double LengthSquared() const
    {
        return std::pow(u[0], 2) + std::pow(u[1], 2) + std::pow(u[2], 2);
    }

    double Length() const
    {
        return std::sqrt(LengthSquared());
    }

    // Operators
    double operator[](int i) const { return u[i]; }
    double &operator[](int i) { return u[i]; }

    Vec3 operator-() const { return Vec3(-u[0], -u[1], u[2]); }

    Vec3 &operator+=(const Vec3 &v)
    {
        u[0] += v.u[0];
        u[1] += v.u[1];
        u[2] += v.u[2];

        return *this;
    }

    Vec3 &operator*=(const double t)
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

// Other usages of a Vec3.
using Point3 = Vec3; // 3D point
using Color = Vec3;  // RGB

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

inline Vec3 operator*(double t, const Vec3 &v)
{
    return Vec3(t * v.x(), t * v.y(), t * v.z());
}

inline Vec3 operator*(const Vec3 &v, double t)
{
    return t * v;
}

inline Vec3 operator/(Vec3 v, double t)
{
    return (1 / t) * v;
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
