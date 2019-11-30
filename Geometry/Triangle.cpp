#include "Triangle.h"

/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 19.06.2019.
 */

Triangle::Triangle() {
    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;
}

Triangle::~Triangle() {
    delete p1;
    delete p2;
    delete p3;
}

Triangle::Triangle(Point p1, Point p2, Point p3) {
    this->p1 = new Point(p1);
    this->p2 = new Point(p2);
    this->p3 = new Point(p3);
}

Triangle::Triangle(Point *p1, Point *p2, Point *p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::Triangle(const Triangle &triangle) {
    p1 = new Point(*triangle.p1);
    p2 = new Point(*triangle.p2);
    p3 = new Point(*triangle.p3);
}

double Triangle::getSurface() const {
    double perimeter = getPerimeter() / 2;
    return (sqrt(perimeter *
                 (perimeter - Point::getLengthBetweenPoints(p1, p2)) +
                 (perimeter - Point::getLengthBetweenPoints(p1, p3)) +
                 (perimeter - Point::getLengthBetweenPoints(p2, p3))));
}

double Triangle::getPerimeter() const {
    return Point::getLengthBetweenPoints(p1, p2) +
           Point::getLengthBetweenPoints(p1, p3) +
           Point::getLengthBetweenPoints(p2, p3);
}

void Triangle::translate(Vector translater) {

}

void Triangle::show() const {
    std::cout << "Triangle" << std::endl;
    Figure::show();
}
