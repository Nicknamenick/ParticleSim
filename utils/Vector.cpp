#include "Vector.h"
#include "Point.h"

Vector Vector::fromPoints(const Point& a, const Point& b) {
    return {b.x - a.x, b.y - a.y};
}