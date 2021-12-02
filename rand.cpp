#include "rand.hpp"


        Rand::Rand() {
            operand = rand() % 100;
        }
        Rand::Rand(int seed) { 
            srand(seed);
            operand = rand() % 100;
        };
         double Rand::evaluate() { return operand; }
         std::string Rand::stringify() {
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(1) << operand;
            return ss.str();
        }
         int Rand::number_of_children() { return 1; }
         Base* Rand::get_child(int i) { return new Op(operand); }
         void Rand::accept (Visitor* v, int index) { v->visit_rand(this); }