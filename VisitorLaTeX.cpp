#include "VisitorLaTeX.hpp"

         VisitorLaTeX::~VisitorLaTeX() = default;

        // Nodes with no children are visited only once (index = 0)
         void VisitorLaTeX::visit_op(Op* node) {
            double leafValue = node->evaluate();
            std::string leafValueString = std::to_string(leafValue);
            output_LaTeX += "{" + leafValueString + "}";
        }
         void VisitorLaTeX::visit_rand(Rand* node) {
            double leafValue = node->evaluate();
            std::string leafValueString = std::to_string(leafValue);
            output_LaTeX += "{" + leafValueString + "}";
        }

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
         void VisitorLaTeX::visit_add_begin(Add* node) {
            output_LaTeX += "{";
        }
         void VisitorLaTeX::visit_add_middle(Add* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}+";
        }
         void VisitorLaTeX::visit_add_end(Add* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
         void VisitorLaTeX::visit_sub_begin(Sub* node) {
            output_LaTeX += "{";
        }
         void VisitorLaTeX::visit_sub_middle(Sub* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}-";
        }
         void VisitorLaTeX::visit_sub_end(Sub* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
         void VisitorLaTeX::visit_mult_begin(Mult* node) {
            output_LaTeX += "{";
        }
         void VisitorLaTeX::visit_mult_middle(Mult* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}\cdot";
        }
         void VisitorLaTeX::visit_mult_end(Mult* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
         void VisitorLaTeX::visit_div_begin(Div* node) {
            output_LaTeX += "{\frac";
        }
         void VisitorLaTeX::visit_div_middle(Div* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}";
        }
         void VisitorLaTeX::visit_div_end(Div* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
         void VisitorLaTeX::visit_pow_begin(Pow* node) {
            output_LaTeX += "{";
        }
         void VisitorLaTeX::visit_pow_middle(Pow* node) {
            double firstChildValue = node->get_child(0)->evaluate();
            std::string firstChildValueString = std::to_string(firstChildValue);
            output_LaTeX += "{" + firstChildValueString + "}^";
        }
         void VisitorLaTeX::visit_pow_end(Pow* node) {
            double secondChildValue = node->get_child(1)->evaluate();
            std::string secondChildValueString = std::to_string(secondChildValue);
            output_LaTeX += "{" + secondChildValueString + "}}";
        }
        std::string VisitorLaTeX::getString() { return output_LaTeX; }

std::string PrintLaTeX(Base* ptr) 
{
    Iterator iter(ptr);
    VisitorLaTeX* visitor;
    for(iter; !iter.is_done(); iter.next())
    {
        iter.current_node()->accept(visitor, iter.current_index());
    }
    return visitor->getString();
}