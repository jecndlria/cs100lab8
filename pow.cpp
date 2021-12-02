#include "pow.hpp"


        Pow::Pow() : Base() {}
        Pow::Pow(Base* lhs, Base* rhs) { operands.push_back(lhs); operands.push_back(rhs); }
         double Pow::evaluate() { return std::pow(operands[0]->evaluate(), operands[1]->evaluate()); }
         std::string Pow::stringify() { return "(" + operands[0]->stringify() + " ** " + operands[1]->stringify() + ")"; }
         int Pow::number_of_children() { return operands.size(); }
         Base* Pow::get_child(int i) {
            if (i > this->number_of_children()) return nullptr;
            else return operands[i];
        }
         void Pow::accept (Visitor* v, int index) {
            switch(index) {
                case 0: { v->visit_pow_begin(this); break; }
                case 1: { v->visit_pow_middle(this); break; }
                case 2: { v->visit_pow_end(this); break; }
            }
        }