#include <exception>
#include <stack>
#include <string>

class RPN
{
    private:
        const std::string   OPERANDS = "+-*/";
        std::stack<int>     _operationStack;

        void    handleRPN(std::string &input);
        void    performOperation(char operation);
        bool    isOperand(char c);
        void    printResult(void);

    public:
        RPN();
        RPN(const RPN &cpy);
        RPN &operator=(RPN const &rhs);
        ~RPN();

        void    runRPN(std::string &input);

        class invalidOperation : public std::exception
        {
          virtual  const char *what() const throw();
        };
        class invalidArgument : public std::exception
        {
         virtual const char* what() const throw();
        };
        class invalidDivision : public std::exception
        {
            virtual const char * what() const throw();
        };
};
