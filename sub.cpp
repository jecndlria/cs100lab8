#include "sub.hpp"


        Sub::Sub() : Base() {}
        Sub::Sub(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
         double Sub::evaluate() { return operands[0]->evaluate() - operands[1]->evaluate(); }
         std::string Sub::stringify() { return "(" + operands[0]->stringify() + " - " + operands[1]->stringify() + ")"; }
         int Sub::number_of_children() { return operands.size(); }
         Base* Sub::get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
         void Sub::accept (Visitor* v, int index) {
            switch(index) {
                case 0: { v->visit_sub_begin(this); break; }
                case 1: { v->visit_sub_middle(this); break; }
                case 2: { v->visit_sub_end(this); break; }
            }
        }