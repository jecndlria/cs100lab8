#pragma once
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
        Div();
        Div(Base* lhs, Base* rhs);
        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);
        virtual void accept (Visitor* v, int index);
};

#endif