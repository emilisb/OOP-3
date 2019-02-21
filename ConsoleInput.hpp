//
//  ConsoleInput.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef ConsoleInput_hpp
#define ConsoleInput_hpp

#include <string>

class ConsoleInput {
public:
    static bool getBool(std::string question, char trueValue = 't', char falseValue = 'n');
};

#endif /* ConsoleInput_hpp */
