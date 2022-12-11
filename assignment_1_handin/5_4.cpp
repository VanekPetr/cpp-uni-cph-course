
#include <iostream>
#include "cmath"
#include "5_4.h"
#include <cassert>


double calc_std(double a[], int length) {
    assert(length>0);
    if(length == 1){
        return 0;
    }
    else{
        double sum = 0.0;
        for(int i=0; i<length; i++){
            sum += pow(a[i] - calc_mean(a, length),2);
        }
        double res = sqrt(sum/(length - 1));
        return res;
    }
}

double calc_mean(double a[], int length) {
    assert(length>0);
    double sum = 0.0;
    for(int i=0; i<length; i++){
        sum += a[i];
    }
    double res = sum/length;
    return res;
}



