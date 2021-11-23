#ifndef __MULT_HPP__
#define __MULT_HPP__
#include "base.hpp"
#include "op.hpp"
#include <string>
#include <vector>
class Mult : public Base 
{
    private:
        std::vector<Base*> operands;
    public:
        Mult() : Base() {};
        Mult(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
        virtual double evaluate() { return operands[0]->evaluate() * operands[1]->evaluate(); }
        virtual std::string stringify() { return "(" + operands[0]->stringify() + " * " + operands[1]->stringify() + ")"; }
        virtual int number_of_children() { return operands.size(); }
        virtual Base* get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
};

#endif
