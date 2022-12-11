//
//  main.cpp
//  LogisticRegression
//
//  Created by Petr Vaněk on 06/06/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include "armadillo.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace arma;


int main(int argc, char* argv[])
{
    
    ///////////////////////////
    ////// READING DATA ///////
    ///////////////////////////
    
    //Read dataX from dist
    mat x(200, 34);
    std::ifstream read_file("dataX.dat");
    assert(read_file.is_open());
    for (int i = 0; i<200; i++)
    {
        for (int j = 0; j<34; j++)
        {
            read_file >> x(i,j);
        }
    }
    read_file.close();
    
    //Read dataXtest from disk
    mat x_test(151, 34);
    std::ifstream read_file_test("dataXtest.dat");
    assert(read_file_test.is_open());
    for (int i = 0; i<151; i++)
    {
        for (int j = 0; j<34; j++)
        {
            read_file_test >> x_test(i,j);
        }
    }
    read_file_test.close();
    
    //Read dataY from disk
    double y[200];
    std::ifstream read_file_y("dataY.dat");
    assert(read_file_y.is_open());
    for (int i = 0; i<200; i++)
    {
        read_file_y >> y[i];
    }
    read_file_y.close();
    
    
    ////////////////////////////////////////
    ////////// Logistic Regression /////////
    ////////////////////////////////////////
    
    double alpha = 0.5;
    double epsilon = 10e-7;
    double result[151];
    vec w;
    vec w_new;
    rowvec sum;
    vec sum_new;
    rowvec f;
    
    //Initialization
    w.zeros(34);
    w_new.zeros(34);
    sum.zeros(34);
    
    
    //First computation of w
    for(int k=0; k<200; k++)
    {
        sum = sum + ((y[k])/(1 + exp(y[k]*(x.row(k)*w)))*x.row(k));
    }
    sum_new = conv_to<vec>::from(sum);
    w = w + (alpha/200)*sum_new;
    
    //Condition
    while(arma::norm((alpha/200)*sum_new,2) >= epsilon)
    {
        w_new = w;
        sum.zeros(34);
        for(int k=0; k<200; k++)
        {
            sum = sum + ((y[k])/(1 + exp(y[k]*(x.row(k)*w_new)))*x.row(k));
        }
        sum_new = conv_to<vec>::from(sum);
        w = w_new + (alpha/200)*sum_new;
    }
    
    
    
    for(int i=0; i<151; i++)
    {
        f = x_test.row(i)*w;
        
        //Save result
        if(f[0] > 0)
        {
            result[i] = 1;
        }
        else
        {
            result[i] = -1;
        }
    }
    
    
    
    
    /////////////////////////////
    //////// WRITING DATA ///////
    /////////////////////////////
    
    std::ofstream write_output("LogReg.dat");
    assert(write_output.is_open());
    for (int i=0; i<151; i++)
    {
        write_output << result[i] << "\n";
    }
    write_output.close();
    
    
    
    
    
    
    return 0;
}
