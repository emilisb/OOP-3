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

//#define _CONTAINER_LIST_
//#define _CONTAINER_DEQUE_
//#define _CONTAINER_VECTOR_
#define _CONTAINER_MY_VECTOR_

#include <string>
#include <fstream>
#include <deque>
#include <list>
#include <vector>
#include "vector.h"

#include "Student.hpp"
#include "RandomGenerator.hpp"

#ifdef _CONTAINER_DEQUE_
    #define CONTAINER "Deque"
    typedef std::deque<Student> Collection;
#elif defined(_CONTAINER_LIST_)
    #define CONTAINER "List"
    typedef std::list<Student> Collection;
#elif defined(_CONTAINER_VECTOR_)
    #define CONTAINER "Vector"
    typedef std::vector<Student> Collection;
#else
    #define CONTAINER "My Vector"
    typedef vector<Student> Collection;
#endif

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
    void pushByType();
    void moveBadStudents();
    void printFileHeader(std::ofstream &file);
    void printStudentToFile(std::ofstream &file, const Student &student);
    void writeStudentsByTypeToFile(string badStudentsFilename, string goodStudentsFilename);
    void writeGroupedStudentsToFile(string badStudentsFilename, string goodStudentsFilename);
    void writeMovedBadStudentsToFile(string badStudentsFilename, string goodStudentsFilename);
    
    char finalResultMode;
private:
    Collection students;
    Collection goodStudents;
    Collection badStudents;
    
    void calculateMedian();
    void calculateAverage();
    
    string getFinalResultLabel();
    
    Student getRandomStudent(int numOfHomework, int id);
    Student getStudentFromInput();
    
    RandomGenerator randomGenerator;
};

#endif /* StudentCollection_hpp */
