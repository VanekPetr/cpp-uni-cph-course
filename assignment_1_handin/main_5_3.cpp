#include "5_3.h"
#include <iostream>


int main(){
    double x=1;
    double y=2;
    
    swap_pointer(&x, &y);
    std::cout<< x << " " << y << "\n";
    
    swap_ref(x,y);
    std::cout<< x << " " << y << "\n";
    
	return 0;
}
