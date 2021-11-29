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
    Base* three = new Rand();
    Base* seven = new Rand();
    Base* four = new Rand();
    Base* two = new Rand();
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two); 

    //std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    std::cout << PrintLaTeX(minus); 
    return 0;
}
