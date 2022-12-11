//
//  FileNotOpenException.cpp
//  9_1
//
//  Created by Petr Vaněk on 07/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "FileNotOpenException.hpp"
#include "Exception.hpp"

FileNotOpenException::FileNotOpenException(std::string prob): Exception("FILE", prob)
{
}
