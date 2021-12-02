#pragma once
#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"
#include "op.hpp"
#include <string>
#include <vector>
class Add : public Base 
{
    private:
        std::vector<Base*> operands;
        //Op* lhs;
        //Op* rhs;
    public:
        Add();
        ~Add() {for (int i = 0; i < operands.size(); i++) {delete operands[i]; };}
        Add(Base* lhs, Base* rhs);
        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);
        virtual void accept (Visitor* v, int index);
};

#endif
