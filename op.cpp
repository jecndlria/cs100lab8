#include "op.hpp"


        Op::Op(double value) : operand(value){ };
        Op::Op() : operand(0) {};
         double Op::evaluate() { return operand; }
         std::string Op::stringify() {
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(1) << operand;
            return ss.str();
        }
         int Op::number_of_children() { return 0; }
         Base* Op::get_child(int i) { return nullptr; }
         void Op::accept (Visitor* v, int index) { v->visit_op(this); }