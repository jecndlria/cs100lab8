#include "mult.hpp"


        Mult::Mult() : Base() {};
        Mult::Mult(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
         double Mult::evaluate() { return operands[0]->evaluate() * operands[1]->evaluate(); }
         std::string Mult::stringify() { return "(" + operands[0]->stringify() + " * " + operands[1]->stringify() + ")"; }
         int Mult::number_of_children() { return operands.size(); }
         Base* Mult::get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
         void Mult::accept (Visitor* v, int index) {
            switch(index) {
                case 0: v->visit_mult_begin(this);
                case 1: v->visit_mult_middle(this);
                case 2: v->visit_mult_end(this);
            }
        }