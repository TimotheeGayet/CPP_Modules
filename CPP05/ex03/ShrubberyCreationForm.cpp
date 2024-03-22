#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::CantOpenException::what() const throw() {
    return "Can't open file";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowToExecuteException();
    std::ofstream f;
    std::string filename = this->_target + "_shrubbery";
    f.open(filename.c_str());
    if (!f.is_open())
        throw CantOpenException();
    f << "      _-_" << std::endl;
    f << "   /~~   ~~\\" << std::endl;
    f << " /~~   (  ) ~~\\" << std::endl;
    f << "{(   )~~  ( ) ()}" << std::endl;
    f << " \\  _-  ~  -_  /" << std::endl;
    f << "   ~    \\ /    ~" << std::endl;
    f << "        | |" << std::endl;
    f << "        | |" << std::endl;
    f << "        | |" << std::endl;
    f << "      \\ _ /" << std::endl;
    f.close();
}