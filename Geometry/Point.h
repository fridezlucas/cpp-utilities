/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#ifndef CPP_UTILITIES_POINT_H
#define CPP_UTILITIES_POINT_H


#include <ostream>

/**
 * Point class
 * Represent a 2 dimensional Point
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
class Point {
private:
    int x;
    int y;

public:
    Point();

    Point(int x, int y);

    Point(const Point &point);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    Point &operator=(const Point &point);

    friend std::ostream &operator<<(std::ostream &s, const Point &point);

    static double getLengthBetweenPoints(Point *p1, Point *p2);
};


#endif //CPP_UTILITIES_POINT_H
