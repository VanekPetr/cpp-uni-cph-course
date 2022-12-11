//
//  GraduateStudent.cpp
//  7_1
//
//  Created by Petr Vaněk on 06/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <stdio.h>
#include "Student.hpp"
#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent() : Student()
{
    fullTime = 0;
}

GraduateStudent::GraduateStudent(std::string Name, double fines, double fees, bool FullTime)
{
    name = Name;
    SetLibraryFines(fines);
    tuition_fees = fees;
    fullTime = FullTime;
}

double GraduateStudent::MoneyOwed() const{
    return GetLibraryFines();
}
