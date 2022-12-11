//
//  OutOfRangeException.cpp
//  9_1
//
//  Created by Petr Vaněk on 07/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "Exception.hpp"
#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob) : Exception("FILE",prob)
{
}
