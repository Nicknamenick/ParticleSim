#ifndef PARTICLELIFE_POINT_H
#define PARTICLELIFE_POINT_H

#include <string>
#include <cmath>
#include "Vector.h"

class Point {
public:
    float x;
    float y;

    Point(const float x, const float y) : x(x), y(y) {}

    [[nodiscard]] std::string toString() const noexcept {
        return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    void move(const Vector& v) {
        this->x += v.x;
        this->y += v.y;
    }

    [[nodiscard]] float distanceTo(const Point& other) const noexcept {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }


};

#endif //PARTICLELIFE_POINT_H
