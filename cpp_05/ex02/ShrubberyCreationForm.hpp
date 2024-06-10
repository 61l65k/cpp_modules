#pragma once

#include "AForm.hpp"

#define ERR_OPEN_TREE_FILE "Error opening file for tree creation."
#define TREE "\
          v\n\
        >X<\n\
         A\n\
        d$b\n\
      .d\\$$b.\n\
    .d$i$$\\$$b.\n\
       d$$@b\n\
      d\\$$$ib\n\
    .d$$$\\$$$b\n\
  .d$$@$$$$\\$$ib.\n\
      d$$i$$b\n\
     d\\$$$$@$b\n\
  .d$@$$\\$$$$$@b.\n\
.d$$$$i$$$\\$$$$$$b.\n\
        ###\n\
        ###\n\
        ###\n"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();
        enum {e_gradeToSign = 145, e_gradeToExecute = 137};
        void exec_action(const Bureaucrat &executioner) const;
        void changeTarget(std::string const & target);
        std::string const & getTarget() const;
    private:
        std::string _target;
};
