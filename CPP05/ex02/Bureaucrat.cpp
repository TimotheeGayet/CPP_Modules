#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::string Bureaucrat::getName( void )
{
    return this->_name;
}

int &Bureaucrat::getGrade( void )
{
    return this->_grade;
}

void Bureaucrat::incrementGrade( void )
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade( void )
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form){
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}