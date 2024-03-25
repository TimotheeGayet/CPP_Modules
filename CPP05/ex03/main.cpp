#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern intern;
    Bureaucrat bureaucrat("bureaucrat", 1);
    AForm *form = NULL;

    try {
        form = intern.makeForm("presidential pardon", "target");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        form = intern.makeForm("robotomy request", "target");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        form = intern.makeForm("shrubbery creation", "target");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        form = intern.makeForm("nonexistent form", "target");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
