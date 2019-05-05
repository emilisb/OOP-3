//
//  StudentCollection.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <algorithm>

#include "StudentCollection.hpp"
#include "Console/Table.hpp"
#include "Console/Row.hpp"
#include "Console/Console.hpp"

using std::cout;
using std::endl;

void StudentCollection::printFileHeader(std::ofstream &file) {
    file << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas" << '\n';
}

void StudentCollection::printStudentToFile(std::ofstream &file, const Student &student) {
    file << student.getFirstName() << " " << student.getLastName() << " ";
    for (int i = 0; i < 5; i++) {
        file << student.getHomeworkResults().at(i) << " ";
    }
    file << student.getExamResult() << '\n';
}

void StudentCollection::writeStudentsByTypeToFile(string badStudentsFilename, string goodStudentsFilename) {
    std::ofstream badStudentsFile(badStudentsFilename);
    std::ofstream goodStudentsFile(goodStudentsFilename);
    
    printFileHeader(badStudentsFile);
    printFileHeader(goodStudentsFile);
    
    for (const auto &student : students) {
        if (student.getIsGood()) {
            printStudentToFile(goodStudentsFile, student);
        } else {
            printStudentToFile(badStudentsFile, student);
        }
    }
}

void StudentCollection::writeGroupedStudentsToFile(string badStudentsFilename, string goodStudentsFilename) {
    std::ofstream badStudentsFile(badStudentsFilename);
    std::ofstream goodStudentsFile(goodStudentsFilename);
    
    printFileHeader(badStudentsFile);
    printFileHeader(goodStudentsFile);
    
    for (const auto &student : badStudents) {
        printStudentToFile(badStudentsFile, student);
    }
    
    for (const auto &student : goodStudents) {
        printStudentToFile(goodStudentsFile, student);
    }
}

void StudentCollection::writeMovedBadStudentsToFile(string badStudentsFilename, string goodStudentsFilename) {
    std::ofstream badStudentsFile(badStudentsFilename);
    std::ofstream goodStudentsFile(goodStudentsFilename);
    
    printFileHeader(badStudentsFile);
    printFileHeader(goodStudentsFile);
    
    for (const auto &student : badStudents) {
        printStudentToFile(badStudentsFile, student);
    }
    
    for (const auto &student : students) {
        printStudentToFile(goodStudentsFile, student);
    }
}

void StudentCollection::generateRandomFile(string filename, int numOfStudents) {
    std::ofstream file(filename);
    printFileHeader(file);
    
    for (int i = 0; i < numOfStudents; i++) {
        Student student = getRandomStudent(5, i);
        printStudentToFile(file, student);
    }
    
    file.close();
}

void StudentCollection::loadFromFile(string filename, int numHomeworkResults) {
    std::ifstream file(filename);
    if (!file.fail()) {
        string tempLine;
        std::getline(file, tempLine); // ignore first line
        
        while (!file.eof()) {
            std::string firstName;
            std::string lastName;
            std::vector<unsigned int> homeworkResults;
            unsigned int examResult;
            file >> firstName >> lastName;
            
            if (firstName == "") {
                break;
            }
            
            int result;
            for (int i = 0; i < numHomeworkResults; i++) {
                file >> result;
                homeworkResults.push_back(result);
            }
            
            file >> examResult;
            
            Student student(firstName, lastName, homeworkResults, examResult);
            students.push_back(student);
        }
    } else {
        std::cout << "Failo skaitymo klaida!" << std::endl;
    }
    
    file.close();
}

Student StudentCollection::getRandomStudent(int numOfHomework, int id) {
    std::string firstName = "Vardas" + std::to_string(id);
    std::string lastName = "Pavarde" + std::to_string(id);
    std::vector<unsigned int> homeworkResults;
    
    if (!numOfHomework) {
        numOfHomework = randomGenerator.getNumber(1, 10);
    }
    
    for (int i = 0; i < numOfHomework; i++) {
        homeworkResults.push_back(randomGenerator.getNumber(1, 10));
    }
    
    unsigned int examResult = randomGenerator.getNumber(1, 10);
    
    return Student(firstName, lastName, homeworkResults, examResult);
}

Student StudentCollection::getStudentFromInput() {
    unsigned int homeworkResult;
    
    std::string firstName = Console::getStringWithQuestion("Vardas (arba /q jeigu norite baigti vesti duomenis):");
    std::string lastName;
    std::vector<unsigned int> homeworkResults;
    unsigned int examResult = 0;
    if (firstName != EXIT_COMMAND) {
        lastName = Console::getStringWithQuestion("Pavardė:");
        bool fillingHomework = true;
        
        while (fillingHomework) {
            homeworkResult = Console::getIntegerWithQuestion("Namų darbų rez. (arba 0 jei norite baigti vesti duomenis):");
            if (homeworkResult != 0) {
                homeworkResults.push_back(homeworkResult);
            } else {
                fillingHomework = false;
            }
        }
        
        examResult = Console::getIntegerWithQuestion("Egzamino rez:");
    }
    
    return Student(firstName, lastName, homeworkResults, examResult);
}

void StudentCollection::loadFromConsole(bool useRandom) {
    if (useRandom) {
        const int numStudents = randomGenerator.getNumber(3, 10);
        
        for (int i = 0; i < numStudents; i++) {
            Student student = getRandomStudent(5, i);
            students.push_back(student);
        }
    } else {
        bool filling = true;
        
        while (filling) {
            Student student = getStudentFromInput();
            
            if (student.getFirstName() == EXIT_COMMAND) {
                filling = false;
            } else {
                students.push_back(student);
            }
        }
    }
}

void StudentCollection::printResults() {
    Table table(3);
    table.setSeparatorRow(1);
    table.addRow( { "Vardas", "Pavarde", getFinalResultLabel() } );
    
    for (auto &student : students) {
        table.addRow( { student.getFirstName(), student.getLastName(), student.getFinalResultString() } );
    }
    
    table.print();
}

void StudentCollection::sortByName() {
#ifdef _CONTAINER_DEQUE_
    students.sort();
#else
    std::sort(students.begin(), students.end());
#endif
}

void StudentCollection::calculateMedian() {
    for (auto &student : students) {
        student.calculateMedian();
    }
}

void StudentCollection::calculateAverage() {
    for (auto &student : students) {
        student.calculateAverage();
    }
}

void StudentCollection::calculateFinal() {
    switch (finalResultMode) {
        case 'v':
            calculateAverage();
            break;
        case 'm':
            calculateMedian();
            break;
    }
}

string StudentCollection::getFinalResultLabel() {
    const string modeLabel = (finalResultMode == 'v' ? "Vid." : "Med.");
    return "Galutinis (" + modeLabel + ")";
}

void StudentCollection::setTypeByFinalResult() {
    for (auto &student : students) {
        student.setGoodStatus();
    }
}

void StudentCollection::pushByType() {
    for (const auto &student : students) {
        if (student.getFinalResult() >= 5) {
            goodStudents.push_back(student);
        } else {
            badStudents.push_back(student);
        }
    }
}

void StudentCollection::moveBadStudents() {
    auto it = std::stable_partition(students.begin(), students.end(), [](Student student) {
        return student.getFinalResult() < 5;
    });
    
    std::move(students.begin(), it, std::back_inserter(badStudents));
    students.erase(students.begin(), it);
}
