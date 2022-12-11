//
//  CalculateExponential.cpp
//  CalculateExponential
//
//  Created by Petr Vaněk on 04/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <stdio.h>
#include "CalculateExponential.hpp"
#include "ComplexNumber.hpp"
#include <cassert>

double CalculateFactorial(double n)
{
    assert (n > 0);
    if(n==1)
    {
        return 1; }
    else
    {
        // n>1
        return n*CalculateFactorial(n-1);
        
    }
}


void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    assert(nMax >= 0);
    // Variables for computations
    ComplexNumber vys[3][3] = {{ComplexNumber(1.0,0.0), ComplexNumber(0.0,0.0), ComplexNumber(0.0,0.0)},
                               {ComplexNumber(0.0,0.0), ComplexNumber(1.0,0.0), ComplexNumber(0.0,0.0)},
                               {ComplexNumber(0.0,0.0), ComplexNumber(0.0,0.0), ComplexNumber(1.0,0.0)}};
    ComplexNumber help[3][3];
    

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            res[i][j] = vys[i][j];
        }
    }
    
    // Computing the formula for nMax >= 1
    for(int l=1; l<=nMax; l++)
    {
        // Multiply A to the power
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                help[i][j] = ComplexNumber(0.0,0.0);
                for(int k = 0; k<3; k++)
                {
                    help[i][j] = help[i][j] + A[i][k]*vys[k][j];
                }
            }
        }
        
        // Help saving
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                vys[i][j] = help[i][j];
            }
        }
        
        // Formula
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                res[i][j] = res[i][j] + (vys[i][j])/CalculateFactorial(l);
            }
        }
    }
    
}
