#pragma once
#ifndef __POW_HPP__
#define __POW_HPP__
#include "base.hpp"
#include "op.hpp"
#include <string>
#include <vector>
#include <cmath>
class Pow : public Base 
{
    private:
        std::vector<Base*> operands;
        //Op* lhs;
        //Op* rhs;
    public:
        Pow();
        Pow(Base* lhs, Base* rhs);
        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);
        virtual void accept (Visitor* v, int index);
};

#endif