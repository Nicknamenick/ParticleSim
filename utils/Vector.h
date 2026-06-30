#ifndef PARTICLELIFE_VECTOR_H
#define PARTICLELIFE_VECTOR_H

#include <string>
#include <cmath>

class Point;

class Vector {
public:
    float x;
    float y;
    Vector(const float x, const float y) : x(x), y(y) {}

    [[nodiscard]] std::string toString() const noexcept {
        return "Vector(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    [[nodiscard]] float length() const noexcept {
        return std::sqrt(x * x + y * y);
    }

    [[nodiscard]] Vector normalized() const noexcept {
        if (const float len = length(); len != 0) return {x / len, y / len};
        return Vector{0, 0};
    }

    [[nodiscard]] Vector operator +(const Vector& other) const noexcept {
        return {x + other.x, y + other.y};
    }

    [[nodiscard]] Vector operator -(const Vector& other) const noexcept {
        return {x - other.x, y - other.y};
    }

    [[nodiscard]] Vector operator *(const float scalar) const noexcept {
        return {x * scalar, y * scalar};
    }

    [[nodiscard]] Vector operator /(const float scalar) const noexcept {
        if (scalar == 0) return {0, 0};
        return {x / scalar, y / scalar};
    }

    static Vector fromPoints(const Point& a, const Point& b);
};

#endif //PARTICLELIFE_VECTOR_H
