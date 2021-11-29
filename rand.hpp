#pragma once
#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "op.hpp"
#include <iomanip>
#include <sstream>
#include <time.h>
#include <unistd.h>

class Rand : public Base {
    public:
        Rand();
        Rand(int seed);
        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);
        virtual void accept (Visitor* v, int index);
    private:
        double operand = 0;
};

#endif //__RAND_HPP__
