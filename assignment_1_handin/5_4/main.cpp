//
//  main.cpp
//  5_4
//
//  Created by Petr Vaněk on 29/04/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "cmath"


double calc_mean(double a[], int length){
    assert(length>0);
    double sum = 0.0;
    for(int i=0; i<length; i++){
        sum += a[i];
    }
    return sum/length;
}

double calc_std(double a[], int length){
    assert(length>0);
    if(length == 1){
        return 0;
    }
    else{
        double sum = 0.0;
        for(int i=0; i<length; i++){
            sum += pow(a[i] - calc_mean(a, length),2);
        }
        return sqrt(sum/(length - 1));
    }
}

int main(int argc, const char * argv[]) {
    int length = 2;
    double array[length];
    array[0] = 4.2;
    array[1] = 4.4;
    
    std::cout<< "The mean is " << calc_mean(array, length) << "\n";
    std::cout<< "The std is " << calc_std(array, length) << "\n";
    return 0;
}
