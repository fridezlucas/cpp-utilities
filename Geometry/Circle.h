/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 19.06.2019.
 */

#ifndef CPP_UTILITIES_CIRCLE_H
#define CPP_UTILITIES_CIRCLE_H


#include "Figure.h"
#include "Point.h"

class Circle : public Figure {
private:
    int radius;
    Point *center;
public:
    Circle();

    virtual ~Circle();

    Circle(int radius);

    Circle(Point *center);

    Circle(int radius, Point *center);

    Circle(Circle& circle);

    void show() const override;

    double getSurface() const override;

    double getPerimeter() const override;

    void translate(Vector translater) override;
};


#endif //CPP_UTILITIES_CIRCLE_H
