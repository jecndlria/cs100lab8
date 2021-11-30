#include <iostream>

#include "visitor.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "VisitorLaTeX.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    srand(time(NULL));
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Div(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two); 

    // add breaks to switch cases
    // fix prints to work like the mult

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    std::cout << std::setprecision(1) << PrintLaTeX(minus) << std::endl;
    return 0;
}
