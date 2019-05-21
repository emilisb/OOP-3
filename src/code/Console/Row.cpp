//
//  Row.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 22/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "Row.hpp"

void Row::addSection(std::string text, size_t width) {
    RowSection section(text, width);
    sections.push_back(section);
}

void Row::print(const std::vector<size_t> &widths) {
    int i = 0;
    std::cout << std::left;
    for (const auto &section : sections) {
        std::cout << std::setw(widths.at(i)) << section.text;
        i++;
    }
    std::cout << std::endl;
}

size_t Row::getSectionWidth(int sectionIndex) {
    try {
        return sections.at(sectionIndex).width;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return 0;
    }
}


