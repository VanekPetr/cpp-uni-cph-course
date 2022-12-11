#include "5_4.h"
#include <iostream>


int main(){
    int length = 2;
    double array[length];
    array[0] = 4.2;
    array[1] = 4.4;
    
    std::cout<< "The mean is " << calc_mean(array, length) << "\n";
    std::cout<< "The std is " << calc_std(array, length) << "\n";
    
	return 0;
}
