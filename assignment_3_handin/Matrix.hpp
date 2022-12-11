#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include <vector>
#include "Vector.hpp"

template<class T> class Matrix
{
private:
    std::vector<T> mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions
public:
	Matrix(const Matrix& otherMatrix);
	Matrix(int numRows, int numCols);
	~Matrix();
	int GetNumberOfRows() const;
	int GetNumberOfColumns() const;
	T& operator()(int i, int j);
	T const& operator()(int i, int j)const;
	//overloaded assignment operator
	Matrix& operator=(const Matrix& otherMatrix);
	Matrix operator-() const; // unary -
	Matrix operator+(const Matrix& m1) const; // binary +
	Matrix operator-(const Matrix& m1) const; // binary -
	// scalar multiplication
	Matrix operator*(double a) const;
    std::vector<T> const& getStorage();
};
//matrix-vector multiplications
template<class T> Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v);
template<class T> Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m);



#endif
#include "Matrix.cpp"



