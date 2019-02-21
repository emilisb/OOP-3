//
//  Student.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <vector>
#include <string>

struct Student {
    std::string firstName;
    std::string lastName;
    std::vector<unsigned int> homeworkResults;
    unsigned int examResult = 0;
    double finalResult = 0;
    
    bool operator<(const Student& rhs) const
    {
        return firstName < rhs.firstName;
    }
};

#endif /* Student_hpp */
