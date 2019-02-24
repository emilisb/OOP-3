//
//  StudentCollection.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>

#include "StudentCollection.hpp"
#include "Console/Table.hpp"
#include "Console/Row.hpp"
#include "Console/Console.hpp"

using std::cout;
using std::endl;

void StudentCollection::loadFromFile(string filename, int numHomeworkResults) {
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

void StudentCollection::loadFromConsole(bool useRandom) {
    bool filling = true;
    unsigned int homeworkResult;
    
    while (filling) {
        Student student;
        student.firstName = Console::getStringWithQuestion("Vardas (arba /q jeigu norite baigti vesti duomenis):");
        if (student.firstName != EXIT_COMMAND) {
            student.lastName = Console::getStringWithQuestion("Pavardė:");
            
            if (useRandom) {
                std::random_device rd; // obtain a random number from hardware
                std::mt19937 eng(rd()); // seed the generator
                std::uniform_int_distribution<> distr(1, 10); // define the range
                
                int numOfHomework = distr(eng);
                
                for (int i = 0; i < numOfHomework; i++) {
                    student.homeworkResults.push_back(distr(eng));
                }
                
                student.examResult = distr(eng);
            } else {
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
            
            students.push_back(student);
        } else {
            filling = false;
        }
    }
}

void StudentCollection::printResults() {
    Table table(3);
    table.addRow( { "Vardas", "Pavarde", getFinalResultLabel() } );
    
    for (auto &student : students) {
        std::stringstream finalResult;
        finalResult << std::fixed << std::setprecision(2) << student.finalResult;
        table.addRow( { student.firstName, student.lastName, finalResult.str() } );
    }
    
    table.print();
}

void StudentCollection::sortByName() {
    std::sort(students.begin(), students.end());
}

void StudentCollection::calculateMedian() {
    for (auto &student : students) {
        double median = 0;
        
        if (!student.homeworkResults.empty()) {
            auto resultsCount = student.homeworkResults.size();
            std::sort(student.homeworkResults.begin(), student.homeworkResults.end());
            
            if (resultsCount % 2 != 0) {
                median = student.homeworkResults.at(resultsCount/2);
            } else {
                median = (double)(student.homeworkResults.at((resultsCount-1)/2) + student.homeworkResults.at(resultsCount/2))/2.0;
            }
        }
        
        student.finalResult = 0.4 * median + 0.6 * student.examResult;
    }
}

void StudentCollection::calculateAverage() {
    for (auto &student : students) {
        unsigned int sum = 0;
        double average = 0;
        
        if (!student.homeworkResults.empty()) {
            for (const auto &result : student.homeworkResults) {
                sum += result;
            }
            
            average = (double)sum / student.homeworkResults.size();
        }
        
        student.finalResult = 0.4 * average + 0.6 * student.examResult;
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
    string modeLabel = (finalResultMode == 'v' ? "Vid." : "Med.");
    return "Galutinis (" + modeLabel + ")";
}
