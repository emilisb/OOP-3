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

class Student {
public:
    Student(std::string first, std::string last, std::vector<unsigned int> results, unsigned int exam) : firstName(first), lastName(last), homeworkResults(results), examResult(exam) {}
    
    inline std::string getFirstName() const { return firstName; }
    inline std::string getLastName() const { return lastName; }
    inline std::vector<unsigned int> getHomeworkResults() const { return homeworkResults; }
    inline double getFinalResult() const { return finalResult; }
    inline unsigned int getExamResult() const { return examResult; }
    inline bool getIsGood() const { return isGood; }
    
    std::string getFinalResultString();
    
    void calculateAverage();
    void calculateMedian();
    
    void setGoodStatus();
    
    bool operator<(const Student& rhs) const
    {
        return firstName < rhs.firstName;
    }
private:
    std::string firstName;
    std::string lastName;
    std::vector<unsigned int> homeworkResults;
    
    double finalResult = 0;
    unsigned int examResult = 0;
    
    bool isGood;
};

#endif /* Student_hpp */
