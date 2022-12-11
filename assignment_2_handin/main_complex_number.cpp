//
//  main.cpp
//  ComplexNumber
//
//  Created by Petr Vaněk on 03/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "ComplexNumber.hpp"

int main(int argc, const char * argv[]) {
    ComplexNumber z1(4.0, 3.0);
    std::cout << "z1 = " << z1 <<"\n";
    std::cout << "Modulus z1 = " << z1.CalculateModulus() << "\n";
    std::cout << "Argument z1 = " << z1.CalculateArgument() << "\n";
    
    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    std::cout << "z2 = z1*z1*z1 = " << z2 << "\n";
    
    ComplexNumber z3;
    z3 = -z2;
    std::cout << "z3 = -z2 = " << z3 << "\n";
    
    ComplexNumber z4;
    z4=z1+z2;
    std::cout<<"z1 + z2 = " << z4 << "\n";
    
    ComplexNumber zs[2];
    zs[0] = z1;
    zs[1] = z2;
    std::cout << "Second element of zs = " << zs[1] << "\n";
    
    // 6.1.1
    std::cout << "The real part of z1 is " << z1.GetRealPart() << "\n";
    std::cout << "The imaginary part of z1 is " << z1.GetImaginaryPart() << "\n";
    
    // 6.1.2
    std::cout << "The real part of z2 is " << RealPart(z2) << "\n";
    std::cout << "The imaginary part of z2 is " << ImaginaryPart(z2) << "\n";
    
    // 6.1.3
    ComplexNumber z_new(z1);
    std::cout << "z_new = " << z_new << "\n";
    
    // 6.1.4
    ComplexNumber z42(42.42);
    std::cout << "z42 = " << z42 << "\n";
    
    // 6.1.5
    ComplexNumber z5;
    z5 = z3.CalculateConjugate();
    std::cout << "z5 = " << z5 << "\n";
    
    // 6.1.6
    z_new.SetConjugate();
    std::cout << "z_new is now " << z_new << "\n";
    
    return 0;
}
