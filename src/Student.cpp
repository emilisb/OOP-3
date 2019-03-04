//
//  Student.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <sstream>
#include <iomanip>
#include <numeric>

#include "Student.hpp"

std::string Student::getFinalResult() {
    std::stringstream result;
    result << std::fixed << std::setprecision(2) << finalResult;
    
    return result.str();
}

void Student::calculateAverage() {
    double average = !homeworkResults.empty() ? std::accumulate(homeworkResults.begin(), homeworkResults.end(), 0.0) / homeworkResults.size() : 0;
    
    finalResult = 0.4 * average + 0.6 * examResult;
}

void Student::calculateMedian() {
    double median = 0;
    
    if (!homeworkResults.empty()) {
        auto resultsCount = homeworkResults.size();
        std::sort(homeworkResults.begin(), homeworkResults.end());
        
        if (resultsCount % 2 != 0) {
            median = homeworkResults.at(resultsCount/2);
        } else {
            median = (double)(homeworkResults.at((resultsCount-1)/2) + homeworkResults.at(resultsCount/2))/2.0;
        }
    }
    
    finalResult = 0.4 * median + 0.6 * examResult;
}

void Student::setGoodStatus() {
    isGood = finalResult >= 5.0;
}
