//
//  Table.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 22/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#define PADDING 3

#include <vector>
#include <string>

#include "Row.hpp"

class Table {
public:
    Table(int col) : columns(col) { };
    void print();
    void addRow(const std::initializer_list<std::string> &sections);
private:
    std::vector<size_t> columnWidths;
    std::vector<Row> rows;
    
    int columns;
    
    void setColumnWidths();
};

#endif /* Table_hpp */
