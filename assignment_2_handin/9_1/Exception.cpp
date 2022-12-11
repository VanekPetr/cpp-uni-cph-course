//
//  Exception.cpp
//  9_1
//
//  Created by Petr Vaněk on 07/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "Exception.hpp"

//Constructor
Exception::Exception(std::string tagString, std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}

void Exception::PrintDebug() const
{
    std::cerr << "** Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}
