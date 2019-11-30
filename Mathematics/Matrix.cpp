/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 20.06.2019.
 */

#include "Matrix.h"

/**
 * Default constructor
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Matrix::Matrix() {
    data = nullptr;
}

/**
 * Constructor
 * @param row {int} number of row
 * @param col {int} number of col
 * @param defaultValue {int} default value for each case
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Matrix::Matrix(int row, int col, int defaultValue) {
    this->row = row;
    this->col = col;

    data = new int *[row];
    for (int r = 0; r < row; ++r) {
        data[r] = new int[col];

        for (int c = 0; c < col; ++c) {
            data[r][c] = defaultValue;
        }
    }
}

/**
 * Copy constructor
 * @param matrix {Matrix} matrix to recopy
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Matrix::Matrix(const Matrix &matrix) {
    this->row = matrix.row;
    this->col = matrix.col;

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            data[r][c] = matrix.data[r][c];
        }
    }
}

/**
 * Fill matrix with a value
 * @param value {int} value
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Matrix::fill(int value) {
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            data[r][c] = value;
        }
    }
}

/**
 * Return a certain row
 * @param row {int} row number
 * @return row {int*}
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
int *&Matrix::operator[](int row) {
    if(row >= this->row){
        throw Exception(errorsNumbers::OutOfRangeRowException, "Unable to reach this row.");
    }
    return data[row];
}

/**
 * Return a certain case
 * @param row {int} row number
 * @param col {int} col number
 * @return {int} case
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
int &Matrix::operator()(int row, int col) {
    if(row >= this->row || col >= this->col){
        throw Exception(errorsNumbers::OutOfRangeCaseException, "Unable to reach this case.");
    }
    return data[row][col];
}

/**
 * Addition of an other matrix
 * @param matrix {Matrix} to addition
 * @return {Matrix} new Matrix
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Matrix Matrix::operator+(const Matrix &matrix) const {
    Matrix newMat(row, col, 0);

    if (row != matrix.row || col != matrix.col) {
        throw Exception(errorsNumbers::AdditionException, "Unable to addition these matrix.\n");
    } else {
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                newMat[r][c] = matrix.data[r][c] + data[r][c];
            }
        }
    }

    return newMat;
}

/**
 * Substract a matrix
 * @param matrix {Matrix} matrix to substract to current
 * @return {Matrix} new Matrix
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Matrix Matrix::operator-(const Matrix &matrix) const {
    Matrix newMat(row, col, 0);

    if (row != matrix.row || col != matrix.col) {
        throw Exception(errorsNumbers::SubstractionException,
                        "Unable to substract matrix given in parameter with this one.\n");
    } else {
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                newMat[r][c] = data[r][c] - matrix.data[r][c];
            }
        }
    }

    return newMat;
}

/**
 * Write matrix on console
 * @param os {ostream}
 * @param matrix {Matrix}
 * @return {ostream}
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    os << "[";

    for (int r = 0; r < matrix.row; ++r) {

        if (r != 0) {
            os << " ";
        }
        os << "[";

        for (int c = 0; c < matrix.col; ++c) {
            os << matrix.data[r][c];

            if (c != matrix.col - 1)
                os << ", ";
        }
        os << "]";

        if (r != matrix.row - 1) {
            os << std::endl;
        }
    }
    os << "]" << std::endl;
    return os;
}

/**
 * Get Unit Matrix
 * @param dimension {int} to get square unit matrix
 * @return {Matrix} Unit Matrix
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Matrix Matrix::unitMatrix(int dimension) {
    Matrix unitMatrix(dimension, dimension, 0);

    for (int r = 0; r < dimension; ++r) {
        for (int c = 0; c < dimension; ++c) {
            if (r == c) {
                unitMatrix[r][c] = 1;
            }
        }
    }

    return unitMatrix;
}
