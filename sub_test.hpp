#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "sub.hpp"
#include "op.hpp"
#include "mult.hpp"
TEST(SubTest, WhatsNineSubtractedByTen) {
    Op* test0 = new Op(9.0);
    Op* test1 = new Op(10.0);
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->evaluate(), 9.0 - 10);
}

TEST(SubTest, WhatsNineSubtractedByTenString) {
    Op* test0 = new Op(9);
    Op* test1 = new Op(10);
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->stringify(), "(9.0 - 10.0)");
}

TEST(SubTest, ZeroSub) {
    Op* test0 = new Op(0);
    Op* test1 = new Op(0);
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->evaluate(), 0);
}

TEST(SubTest, ZeroSubString) {
    Op* test0 = new Op(0);
    Op* test1 = new Op(0);
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->stringify(), "(0.0 - 0.0)");
}

TEST(SubTest, ChildrenTest) {
    Base* test0 = new Sub(new Op(9), new Op(10));
    Base* test1 = new Sub(new Op(21), new Op(19));
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->evaluate(), ((9-10) - (21-19)));
}

TEST(SubTest, ChildrenTestString) {
    Base* test0 = new Sub(new Op(9), new Op(10));
    Base* test1 = new Sub(new Op(21), new Op(19));
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->stringify(), "((9.0 - 10.0) - (21.0 - 19.0))");
}

TEST(SubTest, ChildrenTestStringMult) {
    Base* test0 = new Mult(new Op(9), new Op(10));
    Base* test1 = new Mult(new Op(21), new Op(19));
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->stringify(), "((9.0 * 10.0) - (21.0 * 19.0))");
}

TEST(SubTest, NegativeNumbers) {
    Base* test0 = new Op(-1);
    Base* test1 = new Op(-1);
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->evaluate(), -1.0 - -1.0);
}

TEST(SubTest, NegativeNumbersString) {
    Base* test0 = new Op(-1);
    Base* test1 = new Op(-1);
    Sub* test2 = new Sub(test0, test1);
    EXPECT_EQ(test2->stringify(), "(-1.0 - -1.0)");
}
#endif //__OP_TEST_HPP__