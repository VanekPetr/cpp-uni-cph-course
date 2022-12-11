//
//  main.cpp
//  5_3
//
//  Created by Petr Vaněk on 29/04/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>

void swap_pointer(double *a, double *b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}
