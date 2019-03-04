//
//  RandomGenerator.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 04/03/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include "RandomGenerator.hpp"

RandomGenerator::RandomGenerator() {
    std::random_device rd; // obtain a random number from hardware
    eng.seed(rd()); // seed the generator
}

int RandomGenerator::getNumber(int from, int to) {
    std::uniform_int_distribution<> distr(from, to); // define the range
    
    return distr(eng);
}
