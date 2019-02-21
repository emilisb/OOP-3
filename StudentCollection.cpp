//
//  StudentCollection.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "StudentCollection.hpp"

void StudentCollection::loadFromFile(string filename) {
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
            for (int i = 0; i < HOMEWORK_RESULTS; i++) {
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

int StudentCollection::maxFirstNameLength() {
    int length = 6; // default value is length of string "Vardas"
    
    for (const auto &student : students) {
        length = std::max(static_cast<int>(student.firstName.length()), length);
    }
    
    return length + 3;
}

int StudentCollection::maxLastNameLength() {
    int length = 7; // default value is length of string "Pavarde"
    
    for (const auto &student : students) {
        length = std::max(static_cast<int>(student.lastName.length()), length);
    }
    
    return length + 3;
}
