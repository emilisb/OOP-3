//
//  Student.cpp
//  Uzduotis 3
//
//  Created by Emilis Baliukonis on 21/05/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <vector>
#include "gtest/gtest.h"
#include "../src/code/Student.hpp"

std::vector<unsigned int> homework = {10, 9, 9};

TEST(Info, ShouldHaveName)
{
    Student student{"John", "Doe", homework, 10};
    EXPECT_EQ("John", student.getFirstName());
    EXPECT_EQ("Doe", student.getLastName());
}

TEST(Calculations, Average)
{
    Student student{"John", "Doe", homework, 10};
    student.calculateAverage();
    EXPECT_NEAR(9.73, student.getFinalResult(), 0.01);
}

TEST(Calculations, Median)
{
    Student student{"John", "Doe", homework, 10};
    student.calculateMedian();
    EXPECT_NEAR(9.60, student.getFinalResult(), 0.01);
}
