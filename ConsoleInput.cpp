//
//  ConsoleInput.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include "ConsoleInput.hpp"

using std::cout;
using std::cin;
using std::endl;

bool ConsoleInput::getBool(std::string question, char trueValue, char falseValue) {
    char input = '\0';
    
    while (input != trueValue && input != falseValue) {
        cout
        << question << endl
        << trueValue << " - taip" << endl
        << falseValue << " - ne" << endl;
        cin >> input;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return input == trueValue;
}
