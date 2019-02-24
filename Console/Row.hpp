//
//  Row.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 22/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef Row_hpp
#define Row_hpp

#include <vector>
#include <string>

#include "RowSection.hpp"

class Row {
public:
    void addSection(std::string text, size_t width);
    void print(const std::vector<size_t> &widths);
    
    size_t getSectionWidth(int sectionIndex);
private:
    std::vector<RowSection> sections;
};

#endif /* Row_hpp */
