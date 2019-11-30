/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 19.06.2019.
 */

#ifndef CPP_UTILITIES_TRIANGLE_H
#define CPP_UTILITIES_TRIANGLE_H


#include "Figure.h"

class Triangle : public Figure {
private:
    Point *p1;
    Point *p2;
    Point *p3;

public:
    Triangle();

    virtual ~Triangle();

    Triangle(Point p1, Point p2, Point p3);

    Triangle(Point *p1, Point *p2, Point *p3);

    Triangle(const Triangle &triangle);

    void show() const override;

    double getSurface() const override;

    double getPerimeter() const override;

    void translate(Vector translater) override;
};


#endif //CPP_UTILITIES_TRIANGLE_H
