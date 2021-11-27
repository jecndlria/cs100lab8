#ifndef VISITORLATEX_HPP
#define VISITORLATEX_HPP

#include "visitor.hpp"
#include "base.hpp"

class VisitorLaTeX : public Visitor {
    public:
        virtual ~VisitorLaTeX() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) {
            double leafValue = node->evaluate();
            std::string leafValueString = std::to_string(leafValue);
            output_LaTeX += "{" + leafValueString + "}";
        }
        virtual void visit_rand(Rand* node) {
            double leafValue = node->evaluate();
            std::string leafValueString = std::to_string(leafValue);
            output_LaTeX += "{" + leafValueString + "}";
        }

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) {
            output_LaTeX += "{";
        }
        virtual void visit_add_middle(Add* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}+";
        }
        virtual void visit_add_end(Add* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
        virtual void visit_sub_begin(Sub* node) {
            output_LaTeX += "{";
        }
        virtual void visit_sub_middle(Sub* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}-";
        }
        virtual void visit_sub_end(Sub* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
        virtual void visit_mult_begin(Mult* node) {
            output_LaTeX += "{";
        }
        virtual void visit_mult_middle(Mult* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}\cdot";
        }
        virtual void visit_mult_end(Mult* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
        virtual void visit_div_begin(Div* node) {
            output_LaTeX += "{\frac";
        }
        virtual void visit_div_middle(Div* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}";
        }
        virtual void visit_div_end(Div* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
        virtual void visit_pow_begin(Pow* node) {
            output_LaTeX += "{";
        }
        virtual void visit_pow_middle(Pow* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}^";
        }
        virtual void visit_pow_end(Pow* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
    private:
        std::string output_LaTeX = "$";
};

#endif