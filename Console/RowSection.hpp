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
    RowSection(std::string t, size_t w) : text(t), width(w) { };
    size_t width;
    std::string text;
};

#endif /* RowSection_hpp */
