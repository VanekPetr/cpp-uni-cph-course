//
//  Student.cpp
//  7_1
//
//  Created by Petr Vaněk on 06/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <stdio.h>
#include "Student.hpp"
#include <cassert>

Student::Student()
{
    name = "Undefined";
    library_fines = 0.0;
    tuition_fees = 0.0;
}


Student::Student(std::string Name, double fines, double fees)
{
    name = Name;
    library_fines = fines;
    tuition_fees = fees;
}

void Student::SetLibraryFines(double amount)
{
    if(amount >= 0)
    {
    library_fines = amount;
    }
}

double Student::GetLibraryFines() const
{
    return library_fines;
}

double Student::MoneyOwed() const
{
    return library_fines + tuition_fees;
}

