//
//  Console.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef Console_hpp
#define Console_hpp

#include <string>

class Console {
public:
    static bool getBoolWithQuestion(std::string question, char trueValue = 't', char falseValue = 'n');
    static char getCharWithQuestion(std::string question, std::string option1, std::string option2, char value1, char value2);
    static int getIntegerWithQuestion(std::string question);
    static std::string getStringWithQuestion(std::string question);
};

#endif /* Console_hpp */
