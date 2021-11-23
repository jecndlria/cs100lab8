#ifndef VISITORLATEX_HPP
#define VISITORLATEX_HPP

#include "visitor.hpp"

class VisitorLaTeX : public Visitor {
    public:
        virtual ~VisitorLaTeX() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) {}
        virtual void visit_rand(Rand* node) {}

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) {}
        virtual void visit_add_middle(Add* node) {}
        virtual void visit_add_end(Add* node) {}
        virtual void visit_sub_begin(Sub* node) {}
        virtual void visit_sub_middle(Sub* node) {}
        virtual void visit_sub_end(Sub* node) {}
        virtual void visit_mult_begin(Mult* node) {}
        virtual void visit_mult_middle(Mult* node) {}
        virtual void visit_mult_end(Mult* node) {}
        virtual void visit_div_begin(Div* node) {}
        virtual void visit_div_middle(Div* node) {}
        virtual void visit_div_end(Div* node) {}
        virtual void visit_pow_begin(Pow* node) {}
        virtual void visit_pow_middle(Pow* node) {}
        virtual void visit_pow_end(Pow* node) {}
};

#endif