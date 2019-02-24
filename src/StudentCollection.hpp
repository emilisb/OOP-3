//
//  StudentCollection.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef StudentCollection_hpp
#define StudentCollection_hpp

#define EXIT_COMMAND "/q"

#include <vector>
#include <string>

#include "Student.hpp"

using std::vector;
using std::string;

class StudentCollection {
public:
    void loadFromFile(string filename, int numHomeworkResults = 5);
    void loadFromConsole(bool useRandom = false);
    void printResults();
    void sortByName();
    void calculateFinal();
    
    char finalResultMode;
private:
    vector<Student> students;
    
    void calculateMedian();
    void calculateAverage();
    
    string getFinalResultLabel();
};

#endif /* StudentCollection_hpp */
