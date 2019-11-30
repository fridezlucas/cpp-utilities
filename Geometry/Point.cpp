/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#include <cmath>
#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(const Point &point) {
    x = point.x;
    y = point.y;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

Point &Point::operator=(const Point &p) {
    if (this != &p) {
        x = p.x;
        y = p.y;
    }
    return *this;
}

double Point::getLengthBetweenPoints(Point *p1, Point *p2) {
    return sqrt(pow(abs(p2->x - p1->x), 2) + pow(abs(p2->y - p1->y), 2));
}

std::ostream &operator<<(std::ostream &s, const Point &point) {
    return s << "(" << point.x << "," << point.y << ")";
}
