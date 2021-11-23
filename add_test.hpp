#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "mult.hpp"
TEST(AddTest, WhatsNinePlusTen) {
    Op* test0 = new Op(9.0);
    Op* test1 = new Op(10.0);
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->evaluate(), 19);
}

TEST(AddTest, WhatsNinePlusTenString) {
    Op* test0 = new Op(9);
    Op* test1 = new Op(10);
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->stringify(), "(9.0 + 10.0)");
}

TEST(AddTest, ZeroAdd) {
    Op* test0 = new Op(0);
    Op* test1 = new Op(0);
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->evaluate(), 0);
}

TEST(AddTest, ZeroAddString) {
    Op* test0 = new Op(0);
    Op* test1 = new Op(0);
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->stringify(), "(0.0 + 0.0)");
}

TEST(AddTest, ChildrenTest) {
    Base* test0 = new Add(new Op(9), new Op(10));
    Base* test1 = new Add(new Op(21), new Op(19));
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->evaluate(), 59);
}

TEST(AddTest, ChildrenTestString) {
    Base* test0 = new Add(new Op(9), new Op(10));
    Base* test1 = new Add(new Op(21), new Op(19));
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->stringify(), "((9.0 + 10.0) + (21.0 + 19.0))");
}

TEST(AddTest, ChildrenTestStringMult) {
    Base* test0 = new Mult(new Op(9), new Op(10));
    Base* test1 = new Mult(new Op(21), new Op(19));
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->stringify(), "((9.0 * 10.0) + (21.0 * 19.0))");
}

TEST(AddTest, ChildrenTestMult) {
    Base* test0 = new Mult(new Op(9), new Op(10));
    Base* test1 = new Mult(new Op(21), new Op(19));
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->evaluate(), 489);
}

TEST(AddTest, NegativeNumbers) {
    Base* test0 = new Op(-1);
    Base* test1 = new Op(-1);
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->evaluate(), -2);
}

TEST(AddTest, NegativeNumbersString) {
    Base* test0 = new Op(-1);
    Base* test1 = new Op(-1);
    Add* test2 = new Add(test0, test1);
    EXPECT_EQ(test2->stringify(), "(-1.0 + -1.0)");
}
#endif //__OP_TEST_HPP__