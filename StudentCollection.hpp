//
//  StudentCollection.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef StudentCollection_hpp
#define StudentCollection_hpp

#define HOMEWORK_RESULTS 5

#include <vector>
#include <string>

#include "Student.hpp"

using std::vector;
using std::string;

class StudentCollection {
public:
    vector<Student> students;
    
    void loadFromFile(string filename);
    void sortByName();
    void calculateMedian();
    void calculateAverage();
    
    bool compareByFirstName(const Student &a, const Student &b);
    
    int maxFirstNameLength();
    int maxLastNameLength();
private:
    
};

#endif /* StudentCollection_hpp */
