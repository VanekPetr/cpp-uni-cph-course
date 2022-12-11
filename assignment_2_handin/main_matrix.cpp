//
//  main.cpp
//  Matrix2x2
//
//  Created by Petr Vaněk on 05/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "Matrix2x2.hpp"

int main(int argc, const char * argv[]) {
    Matrix2x2 A(1,2,3,4.3);
    Matrix2x2 B(1,2,3,4);
    Matrix2x2 C;
    Matrix2x2 X;
    C = -A;
    std::cout << A.CalcDeterminant()<<"\n";
    std::cout << C.Getval00() <<"\n";
    
    X = A.CalcInverse();
    std::cout <<X.Getval00()<< " " <<  X.Getval01()<<"\n";
    std::cout <<X.Getval10()<< " " << X.Getval11() <<"\n";
    return 0;
}
