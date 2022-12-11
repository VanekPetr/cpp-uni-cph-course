//
//  main.cpp
//  CalculateExponential
//
//  Created by Petr Vaněk on 04/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "CalculateExponential.hpp"
#include "ComplexNumber.hpp"


int main(int argc, const char * argv[]) {
    int n = 3;
    int nMax = 4;
    
    ComplexNumber** res = new ComplexNumber* [n];
    ComplexNumber** A = new ComplexNumber* [n];
    for(int i=0; i<n; i++){
        A[i] = new ComplexNumber [n];
        res[i] = new ComplexNumber [n];
    }
    
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(4.0, 5.0);
    ComplexNumber z3(6.0, 7.0);
    ComplexNumber z4(0.0);
   
    A[0][0] = z1; A[0][1] = z4; A[0][2] = z4;
    A[1][0] = z4; A[1][1] = z2; A[1][2] = z4;
    A[2][0] = z4; A[2][1] = z4; A[2][2] = z3;
    
    CalculateExponential(A, nMax, res);
    
    std::cout<< res[0][0] << " " << res[0][1] << " " << res[0][2] << "\n";
    std::cout<< res[1][0] << " " << res[1][1] << " " << res[1][2] << "\n";
    std::cout<< res[2][0] << " " << res[2][1] << " " << res[2][2] << "\n";
    return 0;
}
