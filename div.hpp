#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "base.hpp"
#include "op.hpp"
#include <string>
#include <vector>
class Div : public Base 
{
    private:
        std::vector<Base*> operands;
    public:
        Div() : Base() {};
        Div(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
        virtual double evaluate() { return operands[0]->evaluate() / operands[1]->evaluate(); }
        virtual std::string stringify() { return "(" + operands[0]->stringify() + " / " + operands[1]->stringify() + ")"; }
};

#endif