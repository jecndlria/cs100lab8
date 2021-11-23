#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand(1);
    EXPECT_EQ(test->evaluate(), 83);
}

TEST(RandTest, RandEvaluationString) {
    Rand* test = new Rand(1);
    EXPECT_EQ(test->stringify(), "83.0");
}

TEST(RandTest, AnotherRandEvaluateNonZero) {
    Rand* test = new Rand(2);
    EXPECT_EQ(test->evaluate(), 90);
}

TEST(RandTest, AnotherRandEvaluationString) {
    Rand* test = new Rand(2);
    EXPECT_EQ(test->stringify(), "90.0");
}

#endif //__Rand_TEST_HPP__
