#pragma once
#ifndef __SUB_HPP__
#define __SUB_HPP__
#include "base.hpp"
#include "op.hpp"
#include <string>
#include <vector>
class Sub : public Base 
{
    private:
        std::vector<Base*> operands;
    public:
        Sub();
        Sub(Base* lhs, Base* rhs);
        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);
        virtual void accept (Visitor* v, int index);
};

#endif
