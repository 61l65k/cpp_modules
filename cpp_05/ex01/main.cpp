#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    const int grade_to_execute = 42; //Not needed yet
    const int grade_to_get_signed = 100;
    const int bureaucratic_grade = 10;

    try 
    {
        Bureaucrat alice("Alice", bureaucratic_grade);
        Form formA("FormA", grade_to_get_signed, grade_to_execute);

        formA.beSigned(alice);
        alice.signForm(formA);

        Bureaucrat bob("Bob", bureaucratic_grade);
        Form formB("FormB", grade_to_get_signed + 10, grade_to_execute);

        bob.signForm(formB);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
