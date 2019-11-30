/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 19.06.2019.
 */

#include "Circle.h"

Circle::Circle() {

}

Circle::Circle(int radius) {
    this->radius = radius;
}

Circle::Circle(Point *center) {
    this->center = center;
}

Circle::Circle(int radius, Point *center) {
    this->radius = radius;
    this->center = center;
}

Circle::Circle(Circle &circle) {
    radius = circle.radius;
    center = new Point(*circle.center);
}

Circle::~Circle() {
    delete center;
}

double Circle::getSurface() const {
    return M_PI * pow(radius, 2);
}

double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

void Circle::show() const {
    std::cout << "Circle" << std::endl;
    Figure::show();
}

void Circle::translate(Vector translater) {

}
