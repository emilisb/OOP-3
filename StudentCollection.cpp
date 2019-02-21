//
//  StudentCollection.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <algorithm>
#include "StudentCollection.hpp"

void StudentCollection::sortByName() {
    std::sort(students.begin(), students.end());
}

void StudentCollection::calculateMedian() {
    for (auto &student : students) {
        double median = 0;
        
        if (!student.homeworkResults.empty()) {
            int results = student.homeworkResults.size();
            std::sort(student.homeworkResults.begin(), student.homeworkResults.end());
            
            if (results % 2 != 0) {
                median = student.homeworkResults.at(results/2);
            } else {
                median = (double)(student.homeworkResults.at((results-1)/2) + student.homeworkResults.at(results/2))/2.0;
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
            for (int i = 0; i < student.homeworkResults.size(); i++) {
                sum += student.homeworkResults.at(i);
            }
            
            average = (double)sum / student.homeworkResults.size();
        }
        
        student.finalResult = 0.4 * average + 0.6 * student.examResult;
    }
}

int StudentCollection::maxFirstNameLength() {
    int length = 6; // default value is length of string "Vardas"
    
    for (auto &student : students) {
        length = std::max(static_cast<int>(student.firstName.length()), length);
    }
    
    return length + 3;
}

int StudentCollection::maxLastNameLength() {
    int length = 7; // default value is length of string "Pavarde"
    
    for (auto &student : students) {
        length = std::max(static_cast<int>(student.lastName.length()), length);
    }
    
    return length + 3;
}
