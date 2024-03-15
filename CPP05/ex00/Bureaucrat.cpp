#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
        this->grade = other.grade;
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

void Bureaucrat::getName( void )
{
    std::cout << this->name << std::endl;
}

void Bureaucrat::getGrade( void )
{
    std::cout << this->grade << std::endl;
}

void Bureaucrat::incrementGrade( void )
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade( void )
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}