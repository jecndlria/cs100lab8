#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "pow.hpp"

TEST(PowTest, ZeroTest) {
    Base* test0 = new Op(2);
    Base* test1 = new Op(0);
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->evaluate(), 1);
}

TEST(PowTest, ZeroTestString) {
    Base* test0 = new Op(2);
    Base* test1 = new Op(0);
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->stringify(), "(2.0 ** 0.0)");
}

TEST(PowTest, BaseTest) {
    Base* test0 = new Op(2);
    Base* test1 = new Op(1);
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->evaluate(), 2);
} 

TEST(PowTest, BaseTestString) {
    Base* test0 = new Op(2);
    Base* test1 = new Op(1);
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->stringify(), "(2.0 ** 1.0)");
} 

TEST(PowTest, Negative) {
    Base* test0 = new Op(-2);
    Base* test1 = new Op(2);
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->evaluate(), 4);
}

TEST(PowTest, NegativeString) {
    Base* test0 = new Op(-2);
    Base* test1 = new Op(2);
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->stringify(), "(-2.0 ** 2.0)");
}

TEST(PowTest, Children) {
    Base* test0 = new Add(new Op(9), new Op(10));
    Base* test1 = new Add(new Op(1), new Op(1));
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->evaluate(), std::pow(19, 2));
}

TEST(PowTest, ChildrenString) {
    Base* test0 = new Add(new Op(9), new Op(10));
    Base* test1 = new Add(new Op(1), new Op(1));
    Pow* test2 = new Pow(test0, test1);
    EXPECT_EQ(test2->stringify(), "((9.0 + 10.0) ** (1.0 + 1.0))");
}
#endif