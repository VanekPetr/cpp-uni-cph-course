#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <vector>

template<class T> class Vector
{
private:
    std::vector<T> mData; // data stored in vector
	int mSize; // size of vector
public:
	Vector(const Vector& otherVector);
	Vector(int size);
	~Vector();
	int size() const;
	T& operator[](int i); // zero-based indexing
	T const& operator[] (int i)const; // zero-based indexing
	// assignment
	Vector& operator=(const Vector& otherVector);
	Vector operator-() const; // unary -
	Vector operator+(const Vector& v1) const; // binary +
	Vector operator-(const Vector& v1) const; // binary -
	// scalar multiplication
	Vector operator*(double a) const;
	// p-norm method
	double CalculateNorm(int p=2) const;
};

#endif
#include "Vector.cpp"



