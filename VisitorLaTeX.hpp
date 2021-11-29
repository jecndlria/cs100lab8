#pragma once
#ifndef VISITORLATEX_HPP
#define VISITORLATEX_HPP

#include "iterator.hpp"
#include "visitor.hpp"
//#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <sstream>


//class Visitor;
class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class VisitorLaTeX : public Visitor {
    public:
        virtual ~VisitorLaTeX();

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node);
        virtual void visit_rand(Rand* node);

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node);
        virtual void visit_add_middle(Add* node);
        virtual void visit_add_end(Add* node);
        virtual void visit_sub_begin(Sub* node);
        virtual void visit_sub_middle(Sub* node);
        virtual void visit_sub_end(Sub* node);
        virtual void visit_mult_begin(Mult* node);
        virtual void visit_mult_middle(Mult* node);
        virtual void visit_mult_end(Mult* node);
        virtual void visit_div_begin(Div* node);
        virtual void visit_div_middle(Div* node);
        virtual void visit_div_end(Div* node);
        virtual void visit_pow_begin(Pow* node);
        virtual void visit_pow_middle(Pow* node);
        virtual void visit_pow_end(Pow* node);
        std::string getString();
    private:
        std::ostringstream output_LaTeX;
};

std::string PrintLaTeX(Base*);

#endif