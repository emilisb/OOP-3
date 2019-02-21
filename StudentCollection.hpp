//
//  StudentCollection.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef StudentCollection_hpp
#define StudentCollection_hpp

#include <vector>
#include "Student.hpp"

using std::vector;

class StudentCollection {
public:
    vector<Student> students;
    
    void sortByName();
    void calculateMedian();
    void calculateAverage();
    
    bool compareByFirstName(const Student &a, const Student &b);
    
    int maxFirstNameLength();
    int maxLastNameLength();
private:
    
};

#endif /* StudentCollection_hpp */
