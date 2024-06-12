#include "Intern.hpp"

void createForms(Intern &intern, AForm *forms[])
{
    forms[0] = intern.makeForm("shrubbery creation", "Goodday");
    forms[1] = intern.makeForm("robotomy request", "Bob");
    forms[2] = intern.makeForm("presidential pardon", "Badboy");
    forms[3] = intern.makeForm("hello world", "Home");
}

void processForms(Bureaucrat &bureaucrat, AForm *forms[], int numForms)
{
    std::cout << GREEN << bureaucrat << RESET << std::endl;

    for (int i = 0; i < numForms; ++i)
    {
        if (forms[i] != NULL)
        {
            try
            {
                std::cout << BLUE << *forms[i] << RESET << std::endl;
                forms[i]->beSigned(bureaucrat);
                bureaucrat.executeForm(*forms[i]);
            }
            catch (std::exception &e)
            {
                std::cerr << RED << e.what() << RESET << std::endl;
            }
            delete forms[i];
        }
    }
}

int main()
{
    Intern someRandomIntern;
    AForm *forms[4] = {0};

    createForms(someRandomIntern, forms);

    Bureaucrat jeff("Jeff", 3);

    processForms(jeff, forms, 4);

    return 0;
}
