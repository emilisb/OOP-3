//
//  ListCollection.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 12/03/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef ListCollection_hpp
#define ListCollection_hpp

#define EXIT_COMMAND "/q"

#include <list>
#include <string>
#include <fstream>

#include "Student.hpp"
#include "RandomGenerator.hpp"

using std::string;

class ListCollection {
public:
    void generateRandomFile(string filename, int numOfStudents);
    void loadFromFile(string filename, int numHomeworkResults = 5);
    void loadFromConsole(bool useRandom = false);
    void printResults();
    void sortByName();
    void calculateFinal();
    void setTypeByFinalResult();
    void printFileHeader(std::ofstream &file);
    void printStudentToFile(std::ofstream &file, const Student &student);
    void writeStudentsByTypeToFile(string badStudentsFilename, string goodStudentsFilename);
    
    char finalResultMode;
private:
    std::list<Student> students;
    
    void calculateMedian();
    void calculateAverage();
    
    string getFinalResultLabel();
    
    Student getRandomStudent(int numOfHomework, int id);
    Student getStudentFromInput();
    
    RandomGenerator randomGenerator;
};
#endif /* ListCollection_hpp */
