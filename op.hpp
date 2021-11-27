#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <iomanip>
#include <sstream>

class Op : public Base {
    public:
        Op(double value) : operand(value){ };
        Op() : operand(0) {};
        virtual double evaluate() { return operand; }
        virtual std::string stringify() {
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(1) << operand;
            return ss.str();
        }
        virtual int number_of_children() { return 0; }
        virtual Base* get_child(int i) { return nullptr; }

        virtual void accept(Visitor* visitor, int index) {

        }
    private:
        double operand = 0;
};

#endif //__OP_HPP__
