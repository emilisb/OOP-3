//
//  Table.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 22/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <algorithm>

#include "Table.hpp"

void Table::addRow(const std::initializer_list<std::string> &sections) {
    Row row;
    
    for (const auto &text : sections) {
        row.addSection(text, text.length());
    }
    
    rows.push_back(row);
}

void Table::print() {
    setColumnWidths();
    if (separatorRow) {
        addSeparator();
    }
    
    for (auto &row : rows) {
        row.print(columnWidths);
    }
}

void Table::setSeparatorRow(int row) {
    separatorRow = row;
}

void Table::addSeparator() {
    Row separator;
    
    for (const auto &width : columnWidths) {
        separator.addSection(std::string(width, '-'), width);
    }
    
    rows.insert(rows.begin() + separatorRow, separator);
}

void Table::setColumnWidths() {
    for (int sectionIndex = 0; sectionIndex < columns; sectionIndex++) {
        size_t width = 0;

        for (auto &row : rows) {
            width = std::max(width, row.getSectionWidth(sectionIndex));
        }
        
        columnWidths.push_back(width + PADDING);
    }
}
