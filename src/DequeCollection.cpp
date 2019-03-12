//
//  DequeCollection.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 12/03/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <algorithm>

#include "DequeCollection.hpp"
#include "Console/Table.hpp"
#include "Console/Row.hpp"
#include "Console/Console.hpp"

using std::cout;
using std::endl;

void DequeCollection::printFileHeader(std::ofstream &file) {
    file << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas" << '\n';
}

void DequeCollection::printStudentToFile(std::ofstream &file, const Student &student) {
    file << student.firstName << " " << student.lastName << " ";
    for (int i = 0; i < 5; i++) {
        file << student.homeworkResults.at(i) << " ";
    }
    file << student.examResult << '\n';
}

void DequeCollection::writeStudentsByTypeToFile(string badStudentsFilename, string goodStudentsFilename) {
    std::ofstream badStudentsFile(badStudentsFilename);
    std::ofstream goodStudentsFile(goodStudentsFilename);
    
    printFileHeader(badStudentsFile);
    printFileHeader(goodStudentsFile);
    
    for (const auto &student : students) {
        if (student.isGood) {
            printStudentToFile(goodStudentsFile, student);
        } else {
            printStudentToFile(badStudentsFile, student);
        }
    }
}

void DequeCollection::generateRandomFile(string filename, int numOfStudents) {
    Student student;
    std::ofstream file(filename);
    printFileHeader(file);
    
    for (int i = 0; i < numOfStudents; i++) {
        student = getRandomStudent(5, i);
        printStudentToFile(file, student);
    }
    
    file.close();
}

void DequeCollection::loadFromFile(string filename, int numHomeworkResults) {
    std::ifstream file(filename);
    if (!file.fail()) {
        string tempLine;
        std::getline(file, tempLine); // ignore first line
        
        while (!file.eof()) {
            Student student;
            file >> student.firstName >> student.lastName;
            
            if (student.firstName == "") {
                break;
            }
            
            int result;
            for (int i = 0; i < numHomeworkResults; i++) {
                file >> result;
                student.homeworkResults.push_back(result);
            }
            
            file >> student.examResult;
            
            students.push_back(student);
        }
    } else {
        std::cout << "Failo skaitymo klaida!" << std::endl;
    }
    
    file.close();
}

Student DequeCollection::getRandomStudent(int numOfHomework, int id) {
    Student student;
    student.firstName = "Vardas" + std::to_string(id);
    student.lastName = "Pavarde" + std::to_string(id);
    
    if (!numOfHomework) {
        numOfHomework = randomGenerator.getNumber(1, 10);
    }
    
    for (int i = 0; i < numOfHomework; i++) {
        student.homeworkResults.push_back(randomGenerator.getNumber(1, 10));
    }
    
    student.examResult = randomGenerator.getNumber(1, 10);
    
    return student;
}

Student DequeCollection::getStudentFromInput() {
    Student student;
    unsigned int homeworkResult;
    
    student.firstName = Console::getStringWithQuestion("Vardas (arba /q jeigu norite baigti vesti duomenis):");
    if (student.firstName != EXIT_COMMAND) {
        student.lastName = Console::getStringWithQuestion("Pavardė:");
        bool fillingHomework = true;
        
        while (fillingHomework) {
            homeworkResult = Console::getIntegerWithQuestion("Namų darbų rez. (arba 0 jei norite baigti vesti duomenis):");
            if (homeworkResult != 0) {
                student.homeworkResults.push_back(homeworkResult);
            } else {
                fillingHomework = false;
            }
        }
        
        student.examResult = Console::getIntegerWithQuestion("Egzamino rez:");
    }
    
    return student;
}

void DequeCollection::loadFromConsole(bool useRandom) {
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
            
            if (student.firstName == EXIT_COMMAND) {
                filling = false;
            } else {
                students.push_back(student);
            }
        }
    }
}

void DequeCollection::printResults() {
    Table table(3);
    table.setSeparatorRow(1);
    table.addRow( { "Vardas", "Pavarde", getFinalResultLabel() } );
    
    for (auto &student : students) {
        table.addRow( { student.firstName, student.lastName, student.getFinalResult() } );
    }
    
    table.print();
}

void DequeCollection::sortByName() {
    std::sort(students.begin(), students.end());
}

void DequeCollection::calculateMedian() {
    for (auto &student : students) {
        student.calculateMedian();
    }
}

void DequeCollection::calculateAverage() {
    for (auto &student : students) {
        student.calculateAverage();
    }
}

void DequeCollection::calculateFinal() {
    switch (finalResultMode) {
        case 'v':
            calculateAverage();
            break;
        case 'm':
            calculateMedian();
            break;
    }
}

string DequeCollection::getFinalResultLabel() {
    const string modeLabel = (finalResultMode == 'v' ? "Vid." : "Med.");
    return "Galutinis (" + modeLabel + ")";
}

void DequeCollection::setTypeByFinalResult() {
    for (auto &student : students) {
        student.setGoodStatus();
    }
}
