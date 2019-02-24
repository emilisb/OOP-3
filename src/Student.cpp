//
//  Student.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <sstream>
#include <iomanip>

#include "Student.hpp"

std::string Student::getFinalResult() {
    std::stringstream result;
    result << std::fixed << std::setprecision(2) << finalResult;
    
    return result.str();
}
