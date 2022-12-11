

#include <iostream>
#include <fstream>
#include <cassert>


void implicit_Euler(int n){
    assert(n > 1);
    double h = 1/((double)(n));
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
}
