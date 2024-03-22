#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        // Implement this
    }
    return *this;
}

Intern::~Intern() {}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}

AForm *Intern::makeForm(const std::string formName, const std::string target) {
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *form = NULL;

    for (int i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            switch (i) {
                case 0:
                    form = new PresidentialPardonForm(target);
                    break;
                case 1:
                    form = new RobotomyRequestForm(target);
                    break;
                case 2:
                    form = new ShrubberyCreationForm(target);
                    break;
            }
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    throw Intern::FormNotFoundException();
}