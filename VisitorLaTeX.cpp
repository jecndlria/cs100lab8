#include "VisitorLaTeX.hpp"
#include <iostream>

         VisitorLaTeX::~VisitorLaTeX() = default;

        // Nodes with no children are visited only once (index = 0)
         void VisitorLaTeX::visit_op(Op* node) {
            double leafValue = node->evaluate();
            std::ostringstream leafValueString;
            leafValueString << std::fixed << std::setprecision(0) << leafValue; 
            output_LaTeX << std::setprecision(1) << "{" + leafValueString.str() + "}";
        }
         void VisitorLaTeX::visit_rand(Rand* node) {
            double leafValue = node->evaluate();
            std::ostringstream leafValueString; 
            leafValueString << std::fixed << std::setprecision(0) << leafValue; 
            output_LaTeX << std::setprecision(1) << "{" + leafValueString.str() + "}";
        }

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
         void VisitorLaTeX::visit_add_begin(Add* node) {
            output_LaTeX << "{(";
        }
         void VisitorLaTeX::visit_add_middle(Add* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::ostringstream firstChildValueString;
            firstChildValueString << std::fixed << std::setprecision(0) << firstChildValue;;
            output_LaTeX << "+";
        }
         void VisitorLaTeX::visit_add_end(Add* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::ostringstream secondChildValueString;
            secondChildValueString << std::fixed << std::setprecision(0) << secondChildValue;;
            output_LaTeX << ")}";
        }
         void VisitorLaTeX::visit_sub_begin(Sub* node) {
            output_LaTeX << "{(";
        }
         void VisitorLaTeX::visit_sub_middle(Sub* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::ostringstream firstChildValueString;
            firstChildValueString << std::fixed << std::setprecision(0) << firstChildValue;;
            output_LaTeX << "-";
        }
         void VisitorLaTeX::visit_sub_end(Sub* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::ostringstream secondChildValueString;
            secondChildValueString << std::fixed << std::setprecision(0) << secondChildValue;;
            output_LaTeX << ")}";
        }
         void VisitorLaTeX::visit_mult_begin(Mult* node) {
            output_LaTeX << "{(";
        }
         void VisitorLaTeX::visit_mult_middle(Mult* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::ostringstream firstChildValueString;
            firstChildValueString << std::fixed << std::setprecision(0) << firstChildValue;;
            output_LaTeX << "\\cdot";
        }
         void VisitorLaTeX::visit_mult_end(Mult* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::ostringstream secondChildValueString;
            secondChildValueString << std::fixed << std::setprecision(0) << secondChildValue;;
            output_LaTeX << ")}";
        }
         void VisitorLaTeX::visit_div_begin(Div* node) {
            output_LaTeX << std::setprecision(1) << "{\\frac";
        }
         void VisitorLaTeX::visit_div_middle(Div* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::ostringstream firstChildValueString;
            firstChildValueString << std::fixed << std::setprecision(0) << firstChildValue;;
           // output_LaTeX << std::setprecision(1) << "{" + firstChildValueString.str() + "}";
        }
         void VisitorLaTeX::visit_div_end(Div* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::ostringstream secondChildValueString;
            secondChildValueString << std::fixed << std::setprecision(0) << secondChildValue;;
            output_LaTeX << "}";
        }
         void VisitorLaTeX::visit_pow_begin(Pow* node) {
            output_LaTeX << "{(";
        }
         void VisitorLaTeX::visit_pow_middle(Pow* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::ostringstream firstChildValueString;
            firstChildValueString << std::fixed << std::setprecision(0) << firstChildValue;
            output_LaTeX << "^";
        }
         void VisitorLaTeX::visit_pow_end(Pow* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::ostringstream secondChildValueString;
            secondChildValueString << std::fixed << std::setprecision(0) << secondChildValue;;
            output_LaTeX << ")}";
        }
        std::string VisitorLaTeX::getString() { 
            std::string output = output_LaTeX.str();
            output.insert(0, "$");
            return output;
        }

std::string PrintLaTeX(Base* ptr) 
{
    if (!ptr) return "";
    Iterator iter(ptr);
    VisitorLaTeX* visitor = new VisitorLaTeX;
    iter = Iterator(ptr);
    std::string test = "";
    while(!iter.is_done())
    {
        iter.current_node()->accept(visitor, iter.current_index());
        iter.next();
    }

    std::string output = visitor->getString();
    output.push_back('$');
    delete visitor;
    return output;
}