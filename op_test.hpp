#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluationString) {
    Op* test = new Op(8.4);
    EXPECT_EQ(test->stringify(), "8.4");
}

TEST(OpTest, ZeroEvaluation) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, ZeroString) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0.0");
}

TEST(OpTest, NegativeEvaluation) {
    Op* test = new Op(-1.0);
    EXPECT_EQ(test->evaluate(), -1.0);
}

TEST(OpTest, NegativeString) {
    Op* test = new Op(-1.0);
    EXPECT_EQ(test->stringify(), "-1.0");
}

TEST(OpTest, LargePrecisionNumberEvaluate) {
    Op* test = new Op(1.2345678);
    EXPECT_EQ(test->evaluate(), 1.2345678);
}

TEST(OpTest, LargePrecisionNumberString) {
    Op* test = new Op(1.2345678);
    EXPECT_EQ(test->stringify(), "1.2");
}

TEST(OpTest, LargeNumberEvaluate) {
    Op* test = new Op(98765432.1);
    EXPECT_EQ(test->evaluate(), 98765432.1);
}

TEST(OpTest, LargeNumberString) {
    Op* test = new Op(98765432.1);
    EXPECT_EQ(test->stringify(), "98765432.1");
}


#endif //__OP_TEST_HPP__
