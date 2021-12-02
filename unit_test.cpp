#include "gtest/gtest.h"

#include "visitor.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "VisitorLaTeX.hpp"


class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

TEST(TestLaTeXOutput, Empty)
{
  Base* nothing = nullptr;
  ASSERT_EQ(PrintLaTeX(nothing), "");
}

TEST(TestLaTeXOutput, Singleton)
{
  Op* single = new Op(0);
  ASSERT_EQ(PrintLaTeX(single), "${0}$");
}

TEST(TestLaTeXOutput, NinePlusTen)
{
  Base* ninePlusTen = new Add(new Op(9), new Op(10));
  ASSERT_EQ(PrintLaTeX(ninePlusTen), "${({9}+{10})}$");
}
TEST(TestLaTeXOutput, NineMinusTen)
{
  Base* ninePlusTen = new Sub(new Op(9), new Op(10));
  ASSERT_EQ(PrintLaTeX(ninePlusTen), "${({9}-{10})}$");
}
TEST(TestLaTeXOutput, NineMultTen)
{
  Base* ninePlusTen = new Mult(new Op(9), new Op(10));
  ASSERT_EQ(PrintLaTeX(ninePlusTen), "${({9}\\cdot{10})}$");
}
TEST(TestLaTeXOutput, NineDivTen)
{
  Base* ninePlusTen = new Div(new Op(9), new Op(10));
  ASSERT_EQ(PrintLaTeX(ninePlusTen), "${\\frac{9}{10}}$");
}
TEST(TestLaTeXOutput, NinePowTen)
{
  Base* ninePlusTen = new Pow(new Op(9), new Op(10));
  ASSERT_EQ(PrintLaTeX(ninePlusTen), "${({9}^{10})}$");
}
TEST(TestLaTeXOutput, Nested)
{
  Base* three = new Op(3);
  Base* seven = new Op(7);
  Base* four = new Op(4);
  Base* two = new Op(2);
  Base* mult = new Div(seven, four);
  Base* add = new Add(three, mult);
  Base* minus = new Sub(add, two); 
  ASSERT_EQ(PrintLaTeX(minus), "${({({3}+{\\frac{7}{4}})}-{2})}$");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
