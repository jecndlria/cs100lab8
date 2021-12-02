#include "div.hpp"


        Div::Div() : Base() {};
        Div::Div(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
         double Div::evaluate() { return operands[0]->evaluate() / operands[1]->evaluate(); }
         std::string Div::stringify() { return "(" + operands[0]->stringify() + " / " + operands[1]->stringify() + ")"; }
         int Div::number_of_children() { return operands.size(); }
         Base* Div::get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
         void Div::accept (Visitor* v, int index) {
            switch(index) {
                case 0: { v->visit_div_begin(this); break; }
                case 1: { v->visit_div_middle(this); break; }
                case 2: { v->visit_div_end(this); break; }
            }
        }