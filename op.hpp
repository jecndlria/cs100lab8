#pragma once
#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <iomanip>
#include <sstream>

//class Visitor;

class Op : public Base {
    public:
        Op(double value);
        Op();
        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);
        virtual void accept (Visitor* v, int index);
    private:
        double operand = 0;
};

#endif //__OP_HPP__
