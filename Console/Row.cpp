//
//  Row.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 22/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "Row.hpp"

void Row::addSection(std::string text, int width) {
    RowSection section(text, width);
    sections.push_back(section);
}

void Row::print(const std::vector<int> &widths) {
    int i = 0;
    std::cout << std::left;
    for (auto &section : sections) {
        std::cout << std::setw(widths.at(i)) << section.text;
        i++;
    }
    std::cout << std::endl;
}

int Row::getSectionWidth(int sectionIndex) {
    return sections.at(sectionIndex).width;
}


