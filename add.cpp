#include "add.hpp"


        Add::Add() : Base() {}
        Add::Add(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
         double Add::evaluate() { return operands[0]->evaluate() + operands[1]->evaluate(); }
         std::string Add::stringify() { return "(" + operands[0]->stringify() + " + " + operands[1]->stringify() + ")"; }
         int Add::number_of_children() { return operands.size(); }
         Base* Add::get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
         void Add::accept (Visitor* v, int index) {
            switch(index) {
                case 0: { v->visit_add_begin(this); break; } 
                case 1: { v->visit_add_middle(this); break; }
                case 2: { v->visit_add_end(this); break; }
            }
        }