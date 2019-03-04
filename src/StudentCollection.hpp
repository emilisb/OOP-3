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
#include <fstream>

#include "Student.hpp"
#include "RandomGenerator.hpp"

using std::vector;
using std::string;

class StudentCollection {
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
    vector<Student> students;
    
    void calculateMedian();
    void calculateAverage();
    
    string getFinalResultLabel();
    
    Student getRandomStudent(int numOfHomework, int id);
    Student getStudentFromInput();
    
    RandomGenerator randomGenerator;
};

#endif /* StudentCollection_hpp */
