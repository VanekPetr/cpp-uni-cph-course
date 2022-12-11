//
//  main.cpp
//  3_3
//
//  Created by Petr Vaněk on 27/04/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cassert>


int main(int argc, const char * argv[]) {
    double n = 10.0;
    double h = 1/n;
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());
    
    double x = 0;
    double y = 1;
    write_output << x << "," << y << "\n";
    
    for(int i=0; i<n; i++){
        x += h;
        y = y/(1+h);
        write_output << x << "," << y << "\n";
    }
    
    return 0;
}
