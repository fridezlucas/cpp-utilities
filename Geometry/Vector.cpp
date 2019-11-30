/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#include "Vector.h"

/**
 * Default constructor
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Vector::Vector() {
    startPoint = nullptr;
    endPoint = nullptr;
}

/**
 * Destructor
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Vector::~Vector() {
    delete startPoint;
    delete endPoint;
}

/**
 * Constructor
 * Vector from origin to Point given in parameters
 * @param end {Point} End Point
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Vector::Vector(Point end) {
    startPoint = new Point(0,0);
    endPoint = new Point(end.getX(), end.getY());
}

/**
 * Constructor
 * @param start {Point} Start Point
 * @param end {Point} End Point
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Vector::Vector(Point start, Point end) {
    startPoint = new Point(start.getX(), start.getY());
    endPoint = new Point(end.getX(), end.getY());
}

/**
 * Constructor
 * Vector from origin to End Point
 * @param end {Point*} End Point
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Vector::Vector(Point *end) {
    startPoint = new Point(0,0);
    endPoint = end;
}

/**
 * Constructor
 * @param start {Point*} Start Point
 * @param end  {Point*} End Point
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Vector::Vector(Point *start, Point *end) {
    startPoint = start;
    endPoint = end;
}

/**
 * Get Start Point
 * @return {Point*} startPoint
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Point *Vector::getStartPoint() const {
    return startPoint;
}

/**
 * Set StartPoint
 * @param startPoint {Point*} StartPoint
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Vector::setStartPoint(Point *startPoint) {
    Vector::startPoint = startPoint;
}

/**
 * Set StartPoint
 * @param startPoint {Point*} StartPoint
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Vector::setStartPoint(Point startPoint) {
    Vector::startPoint = new Point(startPoint.getX(), startPoint.getY());
}

/**
 * Get EndPoint
 * @return {Point*} EndPoint
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Point *Vector::getEndPoint() const {
    return endPoint;
}

/**
 * Set EndPoint
 * @param endPoint {Point*} End Point
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Vector::setEndPoint(Point *endPoint) {
    Vector::endPoint = endPoint;
}

/**
 * Set EndPoint
 * @param endPoint {Point*} End Point
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Vector::setEndPoint(Point endPoint) {
    Vector::endPoint = new Point(endPoint.getX(), endPoint.getY());
}

/**
 * Get Norm Vector
 * @return {int} norm
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
int Vector::getNorm() const {
    return sqrt(pow(endPoint->getX() - startPoint->getX(), 2) + pow(endPoint->getY() - startPoint->getY(), 2));
}

Vector Vector::operator+(const Vector &vector) const {
    Point* newEndPoint = new Point(vector.endPoint->getX() - vector.startPoint->getX() + endPoint->getX(),
                                   vector.endPoint->getY() - vector.startPoint->getY() + endPoint->getY());

    return Vector(startPoint, newEndPoint);
}

/**
 * Write Vector in outstream
 * @param s {outstream}
 * @param vector {Vector} Vector to describe
 * @return {outstream}
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
std::ostream &operator<<(std::ostream &s, const Vector &vector) {
    return s << "Begin Point = " << *(vector.startPoint) << std::endl
             << "End Point   = " << *(vector.endPoint) << std::endl
             << "Norm        = " << vector.getNorm() << std::endl;
}
