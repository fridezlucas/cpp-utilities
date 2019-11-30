/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#ifndef CPP_UTILITIES_VECTOR_H
#define CPP_UTILITIES_VECTOR_H


#include "Point.h"
#include <cmath>

class Vector {
private:
    Point *startPoint;
    Point *endPoint;

public:
    Vector();

    virtual ~Vector();

    Vector(Point end);

    Vector(Point start, Point end);

    Vector(Point *end);

    Vector(Point *start, Point *end);

    Point *getStartPoint() const;

    void setStartPoint(Point *startPoint);

    void setStartPoint(Point startPoint);

    Point *getEndPoint() const;

    void setEndPoint(Point *endPoint);

    void setEndPoint(Point endPoint);

    int getNorm() const;

    Vector operator+(const Vector &vector) const;

    friend std::ostream &operator<<(std::ostream &s, const Vector &vector);
};


#endif //CPP_UTILITIES_VECTOR_H
