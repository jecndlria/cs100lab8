#pragma once
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
        Mult();
        ~Mult() {for (int i = 0; i < operands.size(); i++) {delete operands[i]; };}
        Mult(Base* lhs, Base* rhs);
        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);
        virtual void accept (Visitor* v, int index);
};

#endif
