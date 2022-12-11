//
//  main.cpp
//  3_1
//
//  Created by Petr Vaněk on 08/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "SparseVector.hpp"





//template class Vector<int>;
//template class Matrix<int>;

int main(int argc, const char * argv[]) {
    
    //Initialization
    Vector<int> first(3);
    Vector<int> second(3);
    Vector<int> v3(3);
    Vector<int> v4(2);
    Vector<int> v5(2);
    Matrix<int> M1(2,2);
    Matrix<int> M2(2,2);

    first[0] = -1; first[1] = 2; first[2] = -3;
    second[0] = 1; second[1] = 2; second[2] = 3;
    v4[0] = 2; v4[1] = 2;
    v3 = second;

    M1(0,0) = 1; M1(0,1) = 2;
    M1(1,0) = 2; M1(1,1) = 1;
    v5 = M1*v4;
    M2 = M1*10;

    
    //First exercise
    std::cout<< first[2] << "\n";
    std::cout<< v3[1] << "\n";
    std::cout<< first.CalculateNorm() << "\n";
    std::cout<< M1(0,1) << "\n";
    std::cout<< M2(1,1) << "\n";
    std::cout<< v5[0] << " "<< v5[1]<< "\n";
    std::cout<< v4[0] << " "<< v4[1]<< "\n";
    std::cout<< M1(0,1) << "\n";
    std::cout<< M1.getStorage()[1] << "\n";

    std::cout<< "\n";
    
    
    
    //Initialization
    SparseVector<double> sparse(3);
    SparseVector<double> s1;
    SparseVector<double> s2(3);
    SparseVector<double> s3(3);
    SparseVector<double> s4(3);
    sparse.setValue(4,2);
    sparse.setValue(4,4);
    sparse.setValue(2,6);
    sparse.setValue(4,5);
    s2.setValue(1,1);
    s2.setValue(2,5);
    s2.setValue(3,3);
    
    std::cout<< sparse.getValue(4)<<"\n";
    std::cout<< sparse.size()<<"\n";
    std::cout<< sparse.nonZeroes()<<"\n";
    std::cout<< sparse.valueNonZero(1)<<"\n";
    std::cout<< sparse.indexNonZero(1)<<"\n";
    
    s3 = s2 + sparse;
    s4 = s2 - sparse;
    
    std::cout<< "\n";
    std::cout<< s3.getValue(4)<<"\n";
    std::cout<< s3.indexNonZero(1)<<"\n";
    std::cout<< s4.valueNonZero(1)<<"\n";
    std::cout<< s4.indexNonZero(2)<<"\n";
    
    
    std::cout<< "\n";
    sparse -= s2;
    std::cout<< sparse.getValue(1)<<"\n";
    
    Matrix<double> A(2,2);
    SparseVector<double> vec(2);
    Vector<double> res(2);
    vec.setValue(1, 2);
    vec.setValue(2, 4);
    A(0,0) = 1; A(0,1) = 2;
    A(1,0) = 1; A(1,1) = 1;
    
    
    std::cout<< "\n";
    res = vec*A;
    std::cout<< res[0]<<"\n";
    res = A*vec;
    std::cout<< res[1]<<"\n";
    
    
    std::cout<< "\n";
    
   
    
    int myints[] = {1};
    std::vector<int> v(myints,myints+1);           // 10 20 30 30 20 10 10 20
    
    std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
    
    std::vector<int>::iterator low,up;
    low=std::lower_bound (v.begin(), v.end(), 1); //          ^
    up= std::upper_bound (v.begin(), v.end(), 20); //                   ^
    
    std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
    
    
    

    
    
   
    
    
    return 0;
}
