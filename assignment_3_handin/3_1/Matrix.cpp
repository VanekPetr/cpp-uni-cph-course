#ifndef MATRIXCPP
#define MATRIXCPP

#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include "Matrix.hpp"
#include "Vector.hpp"


// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
template<class T> Matrix<T>::Matrix(const Matrix& otherMatrix)
{
	mNumRows = otherMatrix.mNumRows;
	mNumCols = otherMatrix.mNumCols;
    mData.reserve(mNumCols*mNumCols);
	for (int i=0; i<(mNumRows*mNumCols); i++)
	{
		mData[i] = otherMatrix.mData[i];
	}
}

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
template<class T> Matrix<T>::Matrix(int numRows, int numCols)
{
	assert(numRows > 0);
	assert(numCols > 0);
	mNumRows = numRows;
	mNumCols = numCols;
	mData.reserve(mNumCols*mNumCols);
	for (int i=0; i<(mNumCols*mNumCols); i++)
	{
		mData[i] = 0.0;
	}
}

// Overwritten destructor to correctly free memory
template<class T> Matrix<T>::~Matrix()
{
	mData.erase(mData.begin(), mData.end());
}

// Method to get number of rows of matrix
template<class T> int Matrix<T>::GetNumberOfRows() const
{
	return mNumRows;
}

// Method to get number of columns of matrix
template<class T> int Matrix<T>::GetNumberOfColumns() const
{
	return mNumCols;
}

// Overloading the round brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template<class T> T& Matrix<T>::operator()(int i, int j)
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i*mNumCols + j];
}

template<class T> T const& Matrix<T>::operator()(int i, int j)const
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i*mNumCols + j];
}

// Overloading the assignment operator
template<class T> Matrix<T>& Matrix<T>::operator=(const Matrix& otherMatrix)
{
	assert(mNumRows = otherMatrix.mNumRows);
	assert(mNumCols = otherMatrix.mNumCols);

	for (int i=0; i<(mNumRows*mNumRows); i++)
    {
			mData[i] = otherMatrix.mData[i];
    
	}
	return *this;
}

// Overloading the unary - operator
template<class T> Matrix<T> Matrix<T>::operator-() const
{
	Matrix mat(mNumRows, mNumCols);
	for (int i=0; i<(mNumRows*mNumCols); i++)
	{
			mat.mData[i] = -mData[i];
	}
	return mat;
}

// Overloading the binary + operator
template<class T> Matrix<T> Matrix<T>::operator+(const Matrix& m1) const
{
	assert(mNumRows == m1.mNumRows);
	assert(mNumCols == m1.mNumCols);
	Matrix mat(mNumRows, mNumCols);
	for (int i=0; i<(mNumRows*mNumCols); i++)
	{
			mat.mData[i] = mData[i] + m1.mData[i];
	}
	return mat;
}

// Overloading the binary - operator
template<class T> Matrix<T> Matrix<T>::operator-(const Matrix& m1) const
{
   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<(mNumRows*mNumCols); i++)
    {
        mat.mData[i] = mData[i] - m1.mData[i];
    }
    return mat;
}

// Overloading scalar multiplication
template<class T> Matrix<T> Matrix<T>::operator*(double a) const
{
   Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<(mNumRows*mNumCols); i++)
    {
        mat.mData[i] = a*mData[i];
    }
   return mat;
}

// Overloading matrix multiplied by a vector
template<class T> Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);
	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

// Overloading vector multiplied by a matrix
template<class T> Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);
	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}

template<class T> std::vector<T> const& Matrix<T>::getStorage()
{
    std::vector<T> result;
    result.reserve(mNumRows*mNumCols);
    for(int i=0; i<(mNumRows*mNumCols);i++)
    {
        T& it = mData[i];
        result.push_back(it);
    }
    return result;
}
#endif
