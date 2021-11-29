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
        Pow() : Base() {}
        Pow(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
        virtual double evaluate() { return std::pow(operands[0]->evaluate(), operands[1]->evaluate()); }
        virtual std::string stringify() { return "(" + operands[0]->stringify() + " ** " + operands[1]->stringify() + ")"; }
        virtual int number_of_children() { return operands.size(); }
        virtual Base* get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
        virtual void accept (Visitor* v, int index) {
            switch(index) {
                case 0: v->visit_pow_begin(this);
                case 1: v->visit_pow_middle(this);
                case 2: v->visit_pow_end(this);
            }
        }
};

#endif