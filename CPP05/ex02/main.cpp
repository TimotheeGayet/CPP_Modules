#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 1);
    PresidentialPardonForm *presidentialPardonForm = new PresidentialPardonForm("presidentialPardonForm");
    RobotomyRequestForm *robotomyRequestForm = new RobotomyRequestForm("robotomyRequestForm");
    ShrubberyCreationForm *shrubberyCreationForm = new ShrubberyCreationForm("shrubberyCreationForm");

    std::cout << *bureaucrat << std::endl;
    std::cout << *presidentialPardonForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *shrubberyCreationForm << std::endl;

    std::cout << std::endl;

    try {
        bureaucrat->signForm(*presidentialPardonForm);
        bureaucrat->executeForm(*presidentialPardonForm);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        bureaucrat->signForm(*robotomyRequestForm);
        bureaucrat->executeForm(*robotomyRequestForm);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        bureaucrat->signForm(*shrubberyCreationForm);
        bureaucrat->executeForm(*shrubberyCreationForm);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    delete bureaucrat;
    delete presidentialPardonForm;
    delete robotomyRequestForm;
    delete shrubberyCreationForm;
    return 0;
}