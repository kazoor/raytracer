#pragma once
#include "../util/math/vec3/vec3.hpp"

class Ray
{
public:
    Ray() {}

    Ray(const Point3 &Origin, const Vec3 &Direction)
        : m_Origin(Origin), m_Direction(Direction) {}

    // Setters
    inline void SetOrigin(Point3 &Origin) { m_Origin = Origin; }
    inline void SetDirection(Vec3 &Direction) { m_Direction = Direction; }

    // Getters
    inline Point3 Origin() const { return m_Origin; }
    inline Vec3 Direction() const { return m_Direction; }

    inline Point3 At(double t) const
    {
        return m_Origin + m_Direction * t;
    }

private:
    Point3 m_Origin;
    Vec3 m_Direction;
};