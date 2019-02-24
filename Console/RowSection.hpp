//
//  RowSection.hpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 22/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef RowSection_hpp
#define RowSection_hpp

#include <string>

struct RowSection {
    RowSection(std::string t, int w) : text(t), width(w) { };
    int width;
    std::string text;
};

#endif /* RowSection_hpp */
