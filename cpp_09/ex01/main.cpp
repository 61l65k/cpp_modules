#include "RPN.hpp"
#include <iostream>

/*
 ------------------- Different math notations: -----------------------------
 
 *** Polish Notation (PN) Visualization: aka Prefix Notation. + 3 4
 
 *** Infix Notation Visualization: 3 + 4. ~~Default notation in maths.
 
 *** Reverse Polish Notation (RPN) Visualization: aka Postfix Notation. 3 4 +

 ---------------------------------------------------------------------------
 *
 ---- RPN (Reverse Polish Notation) ---- Stack based notation. 

 * Example Input: "3 4 + 2 * 7 /"
 *
 * Step-by-step Stack Operations:
 * 
 * Input: 3
 * Stack: [3]
 * 
 * Input: 4
 * Stack: [3, 4]
 * 
 * Input: +
 * Operation: 3 + 4
 * Stack: [7]
 * 
 * Input: 2
 * Stack: [7, 2]
 * 
 * Input: *
 * Operation: 7 * 2
 * Stack: [14]
 * 
 * Input: 7
 * Stack: [14, 7]
 * 
 * Input: /
 * Operation: 14 / 7
 * Stack: [2]
 * 
 * Final Output: 2
 *
 * In RPN, operators are applied to the two most recent operands on the stack.
 * The result is then pushed back onto the stack for further operations.
 */

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string arguments = argv[1];
        RPN rpn;
        try
        {
            rpn.runRPN(arguments);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cerr << "invalid amount of arguments" << std::endl;
    }
}
