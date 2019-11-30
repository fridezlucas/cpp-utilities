/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 19.06.2019.
 */

#ifndef CPP_UTILITIES_FIGURE_H
#define CPP_UTILITIES_FIGURE_H

#include <iostream>
#include <cmath>
#include "Vector.h"

class Figure {

public:
    virtual double getSurface() const = 0;

    virtual double getPerimeter() const = 0;

    virtual void translate(Vector translater) = 0;

    virtual void show() const;

    friend std::ostream &operator<<(std::ostream &s, const Figure &figure);
};


#endif //CPP_UTILITIES_FIGURE_H
