//
//  SparseVector.cpp
//  3_1
//
//  Created by Petr Vaněk on 13/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#ifndef SPARSECPP
#define SPARSECPP
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include "SparseVector.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"


//creates an empty vector of dimensionality 0.
template<class T> SparseVector<T>::SparseVector()
{

}

// Creates a vector of dimensionality dim. It starts with 0 nonzero elements
// which need to be set using setValue
template<class T> SparseVector<T>::SparseVector(unsigned int dim)
{
    assert(dim > 0);
    mValues.reserve(dim);
    mIndices.reserve(dim);
    
}


//sets the value v_i of the vector. if it does not exist it is added
template<class T> void SparseVector<T>::setValue(unsigned int index, T value)
{
    std::vector<int>::iterator low;
    low = std::lower_bound (mIndices.begin(), mIndices.end(), index);
    int it = (low-mIndices.begin());
    
    if(it != std::distance(mIndices.begin(), mIndices.end()))
    {
        assert(mIndices.size() > it && mIndices.size() >= 0);
        if(mIndices[it] != index)
        {
            mIndices.insert(mIndices.begin()+it, index);
            mValues.insert(mValues.begin()+it,value);
        }
        else
        {
            mValues[it] = value;
            mIndices[it] = index;
        }
    }
    else
    {
        mIndices.push_back(index);
        mValues.push_back(value);
    }
    
    
}

//returns the value v_i of the vector. Returns 0 if the value is not stored
template<class T> T SparseVector<T>::getValue(unsigned int index)const
{
    auto it = std::find(mIndices.begin(), mIndices.end(), index);
    if (it != mIndices.end())
    {
        auto position = std::distance(mIndices.begin(), it);
        return mValues[position];
    }
    else
    {
        return 0;
    }
}

//returns the dimensionality of the vector
template<class T> unsigned int SparseVector<T>::size()const
{
    auto length = std::distance(mIndices.begin(), mIndices.end());
    return mIndices[length-1]+1;
}

// returns the number stored elements
template<class T> unsigned int SparseVector<T>::nonZeroes() const
{
    return mIndices.size();
}

//returns the index of the ith stored nonzero entry (in increasing order)
template<class T> unsigned int SparseVector<T>::indexNonZero(unsigned int i) const
{
    assert(i+1<=std::distance(mIndices.begin(), mIndices.end()));
    return mIndices[i];
}

//returns the value of the ith stored nonzero entry (in increasing order)
template<class T> T SparseVector<T>::valueNonZero(unsigned int i) const
{
    assert(i+1<=std::distance(mValues.begin(), mValues.end()));
    return mValues[i];
}

//adds x too the current vector
template<class T> SparseVector<T>& SparseVector<T>::operator+= (SparseVector<T> const& x)
{
    for(int i=0; i< x.nonZeroes(); i++)
    {
        setValue(x.indexNonZero(i), x.valueNonZero(i)+ getValue(x.indexNonZero(i)));
    }
    return *this;
}

//subtracts x from the current vector
template<class T> SparseVector<T>& SparseVector<T>::operator-= (SparseVector<T> const& x)
{
    
    for(int i=0; i< x.nonZeroes(); i++)
    {
        setValue(x.indexNonZero(i), getValue(x.indexNonZero(i)) - x.valueNonZero(i));
    }
    return *this;
}



// computes z= x+y, equivalent to z=x, z+=y
template<class T>
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y)
{
    SparseVector<T> z;
    for(int i=0; i<x.nonZeroes(); i++)
    {
        z.setValue(x.indexNonZero(i), x.valueNonZero(i));
    }
    
    for(int i=0; i<y.nonZeroes(); i++)
    {
        z.setValue(y.indexNonZero(i), x.getValue(y.indexNonZero(i)) + y.valueNonZero(i));
    }
    
    return z;
    
}

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y)
{
    SparseVector<T> z;
    for(int i=0; i<x.nonZeroes(); i++)
    {
        z.setValue(x.indexNonZero(i), x.valueNonZero(i));
    }
    
    for(int i=0; i<y.nonZeroes(); i++)
    {
        z.setValue(y.indexNonZero(i), x.getValue(y.indexNonZero(i)) - y.valueNonZero(i));
    }
    
    return z;
    
}


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x)
{
    assert(A.GetNumberOfColumns() == x.nonZeroes());
    Vector<T> c(A.GetNumberOfColumns());
    for (int i=0;i<A.GetNumberOfRows();i++)
    {
        c[i] = 0;
        for (int j=0;j<A.GetNumberOfColumns();j++)
        {
            c[i] = c[i] + A(i,j)*x.valueNonZero(j);
        }
    }
    return c;
}

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A)
{
    assert(A.GetNumberOfRows() == x.nonZeroes());
    Vector<T> c(A.GetNumberOfRows());
    for (int i=0;i<A.GetNumberOfColumns();i++)
    {
        c[i] = 0;
        for (int j=0;j<A.GetNumberOfRows();j++)
        {
            c[i] = c[i] + x.valueNonZero(j)*A(j,i);
        }
    }
    return c;
    
}



#endif
