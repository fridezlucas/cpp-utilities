/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 20.06.2019.
 */

#ifndef CPP_UTILITIES_MATRIX_H
#define CPP_UTILITIES_MATRIX_H

#include <iostream>
#include "./../Exceptions/Exception.h"

/**
 * Matrix class
 * 2 dimensional matrix
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
class Matrix {
private:
    int **data;
    int row;
    int col;

    enum errorsNumbers {
        OutOfRangeRowException,
        OutOfRangeCaseException,
        AdditionException,
        SubstractionException,
        MultiplicationError
    };

public:
    Matrix();

    Matrix(int row, int col = 1, int defaultValue = 0);

    Matrix(const Matrix &matrix);

    Matrix invert();

    Matrix transpose();

    Matrix det();

    void fill(int value);

    int *&operator[](int row);

    int &operator()(int row, int col);

    Matrix operator+(const Matrix &matrix) const;

    Matrix operator-(const Matrix &matrix) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    static Matrix unitMatrix(int dimension);

};


#endif //CPP_UTILITIES_MATRIX_H
