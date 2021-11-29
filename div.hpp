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
        Div() : Base() {};
        Div(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
        virtual double evaluate() { return operands[0]->evaluate() / operands[1]->evaluate(); }
        virtual std::string stringify() { return "(" + operands[0]->stringify() + " / " + operands[1]->stringify() + ")"; }
        virtual int number_of_children() { return operands.size(); }
        virtual Base* get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
        virtual void accept (Visitor* v, int index) {
            switch(index) {
                case 0: v->visit_div_begin(this);
                case 1: v->visit_div_middle(this);
                case 2: v->visit_div_end(this);
            }
        }
};

#endif