/**
 *
 *   @file Student.hpp
 *   @brief This is header file for student class.
 *   It contains all operations related to one student object
*/

#ifndef Student_hpp
#define Student_hpp

#include <vector>
#include <string>

#include "Person.hpp"

class Student : public Person {
public:
    Student(std::string first, std::string last, std::vector<unsigned int> results, unsigned int exam) : Person{first, last}, homeworkResults(results), examResult(exam) {}
    
    inline std::vector<unsigned int> getHomeworkResults() const { return homeworkResults; }
    inline double getFinalResult() const { return finalResult; }
    inline unsigned int getExamResult() const { return examResult; }
    inline bool getIsGood() const { return isGood; }
    
    std::string getFinalResultString();
    
    void calculateAverage();
    void calculateMedian();
    
    void setGoodStatus();
private:
    std::vector<unsigned int> homeworkResults;
    
    double finalResult = 0;
    unsigned int examResult = 0;
    
    bool isGood;
};

#endif /* Student_hpp */
