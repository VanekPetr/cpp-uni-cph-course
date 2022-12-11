//
//  Matrix2x2.cpp
//  Matrix2x2
//
//  Created by Petr Vaněk on 05/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <stdio.h>
#include "Matrix2x2.hpp"
#include <cassert>
#include <cmath>

// Override default constructor
Matrix2x2::Matrix2x2()
{
    val00 = 0.0; // first row, first column
    val01 = 0.0; // first row, second column
    val10 = 0.0; // second row, first colum
    val11 = 0.0; // second row, second column
}

// Copy constructor
Matrix2x2::Matrix2x2(const Matrix2x2& other)
{
    val00 = other.val00;
    val01 = other.val01;
    val10 = other.val10;
    val11 = other.val11;
}

// Constructor that write imputs Matrix2x2
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
    val00 = a;
    val01 = b;
    val10 = c;
    val11 = d;
}

// Method for computinf determinant
double Matrix2x2::CalcDeterminant() const
{
    return (val00*val11)-(val01*val10);
}

// Method that returns the inverse of the matrix, if it exists
Matrix2x2 Matrix2x2::CalcInverse() const
{
    Matrix2x2 w;
    double det = (val00*val11)-(val01*val10);
    assert(det != 0.0);
    w.val00 = val11/det;
    w.val01 = (-val01)/det;
    w.val10 = (-val10)/det;
    w.val11 = val00/det;
    return w;
}

// Overloading the = (assignment) operator
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;
    val11 = z.val11;
    return *this;
}

// Overloading the unary - operator
Matrix2x2 Matrix2x2::operator-() const
{
    Matrix2x2 A;
    A.val00 = -val00;
    A.val01 = -val01;
    A.val10 = -val10;
    A.val11 = -val11;
    return A;
}

// Overloading the binary + operator
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const
{
    Matrix2x2 A;
    A.val00 = val00 + z.val00;
    A.val01 = val01 + z.val01;
    A.val10 = val10 + z.val10;
    A.val11 = val11 + z.val11;
    return A;
}

// Overloading the binary - operator
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const
{
    Matrix2x2 A;
    A.val00 = val00 - z.val00;
    A.val01 = val01 - z.val01;
    A.val10 = val10 - z.val10;
    A.val11 = val11 - z.val11;
    return A;
}

// Method which returns multiplication of matrix and scalar
void Matrix2x2::MultScalar(double scalar)
{
    val00 = scalar*val00;
    val01 = scalar*val01;
    val10 = scalar*val10;
    val11 = scalar*val11;
}

