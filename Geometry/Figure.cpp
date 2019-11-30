/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 19.06.2019.
 */

#include "Figure.h"

std::ostream &operator<<(std::ostream &s, const Figure &figure) {
    figure.show();
    return s;
}

void Figure::show() const {
    std::cout << "Perimeter = " << getPerimeter() << std::endl
              << "Surface   = " << getSurface()   << std::endl;
}
