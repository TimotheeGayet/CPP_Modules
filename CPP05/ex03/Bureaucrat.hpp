#ifndef BUREAUCRAT_HPP 
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
    private :
        std::string const _name;
        int _grade;

    public :
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception {
            public :
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
                virtual const char *what() const throw();
        };

        std::string getName( void ) const;
        int getGrade( void ) const;

        void incrementGrade( void );
        void decrementGrade( void );

        void signForm(AForm &form);
        void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif