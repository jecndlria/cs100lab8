#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "add.hpp"
#include "op.hpp"
TEST(MultTest, WhatsTimesPlusTen) {
    Op* test0 = new Op(9);
    Op* test1 = new Op(10);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->evaluate(), 90);
}

TEST(MultTest, WhatsNineTimesTenString) {
    Op* test0 = new Op(9);
    Op* test1 = new Op(10);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->stringify(), "(9.0 * 10.0)");
}
TEST(MultTest, NegativeNumberEvaluate) {
    Op* test0 = new Op(-2);
    Op* test1 = new Op(2);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->evaluate(), -4);
}

TEST(MultTest, NegatieNumberString) {
    Op* test0 = new Op(-2);
    Op* test1 = new Op(2);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->stringify(), "(-2.0 * 2.0)");
}

TEST(MultTest, TwoNegativeNumbersEvaluate) {
    Op* test0 = new Op(-2);
    Op* test1 = new Op(-2);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->evaluate(), 4);
}

TEST(MultTest, TwoNegatieNumbersString) {
    Op* test0 = new Op(-2);
    Op* test1 = new Op(-2);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->stringify(), "(-2.0 * -2.0)");
}

TEST(MultTest, PositieTimesZeroEvaluate) {
    Op* test0 = new Op(2);
    Op* test1 = new Op(0);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->evaluate(), 0);
}

TEST(MultTest, PositieTimesZeroeString) {
    Op* test0 = new Op(2);
    Op* test1 = new Op(0);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->stringify(), "(2.0 * 0.0)");
}

TEST(MultTest, ZeroMult) {
    Op* test0 = new Op(0);
    Op* test1 = new Op(0);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->evaluate(), 0);
}

TEST(MultTest, ZeroMultString) {
    Op* test0 = new Op(0);
    Op* test1 = new Op(0);
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->stringify(), "(0.0 * 0.0)");
}

TEST(MultTest, ChildrenTest) {
    Base* test0 = new Mult(new Op(1), new Op(2));
    Base* test1 = new Mult(new Op(3), new Op(2));
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->evaluate(), 12);
}

TEST(MultTest, ChildrenTestString) {
    Base* test0 = new Mult(new Op(9), new Op(10));
    Base* test1 = new Mult(new Op(21), new Op(19));
    Mult* test2 = new Mult(test0, test1);
    EXPECT_EQ(test2->stringify(), "((9.0 * 10.0) * (21.0 * 19.0))");
}
#endif //__OP_TEST_HPP__

