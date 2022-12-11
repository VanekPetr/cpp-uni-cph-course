//
//  main.cpp
//  2_6
//
//  Created by Petr Vaněk on 27/04/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    double initial = 0.0;
    double epsilon = 0.001;
    double x_prev = initial;
    double x_next;
    x_next = x_prev - (exp(x_prev) + pow(x_prev,3) - 5)/(exp(x_prev) + 3*pow(x_prev,2));
    
    while(fabs(x_next-x_prev) >= epsilon){
        x_prev = x_next;
        x_next = x_prev - (exp(x_prev) + pow(x_prev,3) - 5)/(exp(x_prev) + 3*pow(x_prev,2));
    }
    
    std::cout << x_next << "\n";
    
    return 0;
}
