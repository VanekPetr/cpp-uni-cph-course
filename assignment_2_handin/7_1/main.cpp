//
//  main.cpp
//  7_1
//
//  Created by Petr Vaněk on 06/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "Student.hpp"

int main(int argc, const char * argv[]) {
    Student Karel("Karel", 10, 20);
    Karel.SetLibraryFines(30);
    std::cout << Karel.MoneyOwed() << "\n";
    
    return 0;
}
