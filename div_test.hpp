#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include "div.hpp"
#include "add.hpp"
#include "op.hpp"
TEST(DivTest, WhatsNineDividedByTen)
{
  Op *test0 = new Op(9);
  Op *test1 = new Op(10);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->evaluate(), 9.0 / 10.0);
}

TEST(DivTest, WhatsNineDividedByTenString)
{
  Op *test0 = new Op(9);
  Op *test1 = new Op(10);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->stringify(), "(9.0 / 10.0)");
}
TEST(DivTest, NegativeNumberEvaluate)
{
  Op *test0 = new Op(-2);
  Op *test1 = new Op(2);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->evaluate(), -2 / 2);
}

TEST(DivTest, NegatieNumberString)
{
  Op *test0 = new Op(-2);
  Op *test1 = new Op(2);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->stringify(), "(-2.0 / 2.0)");
}

TEST(DivTest, TwoNegativeNumbersEvaluate)
{
  Op *test0 = new Op(-2);
  Op *test1 = new Op(-2);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->evaluate(), -2 / -2);
}

TEST(DivTest, TwoNegatieNumbersString)
{
  Op *test0 = new Op(-2);
  Op *test1 = new Op(-2);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->stringify(), "(-2.0 / -2.0)");
}

TEST(DivTest, PositieDividedByZeroEvaluate)
{
  Op *test0 = new Op(0);
  Op *test1 = new Op(2);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->evaluate(), 0);
}

TEST(DivTest, PositieDividedByZeroeString)
{
  Op *test0 = new Op(2);
  Op *test1 = new Op(0);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->stringify(), "(2.0 / 0.0)");
}

TEST(DivTest, ZeroDivByNegative)
{
  Op *test0 = new Op(0);
  Op *test1 = new Op(-2);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->evaluate(), 0);
}

TEST(DivTest, ZeroDivString)
{
  Op *test0 = new Op(0);
  Op *test1 = new Op(0);
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->stringify(), "(0.0 / 0.0)");
}

TEST(DivTest, ChildrenTest)
{
  Base *test0 = new Div(new Op(5), new Op(5));
  Base *test1 = new Div(new Op(5), new Op(5));
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->evaluate(), ((5 / 5) / (5 / 5)));
}

TEST(DivTest, ChildrenTestString)
{
  Base *test0 = new Div(new Op(9), new Op(10));
  Base *test1 = new Div(new Op(21), new Op(19));
  Div *test2 = new Div(test0, test1);
  EXPECT_EQ(test2->stringify(), "((9.0 / 10.0) / (21.0 / 19.0))");
}
#endif //__OP_TEST_HPP__
