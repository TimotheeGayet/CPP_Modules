#ifndef BUREAUCRAT_HPP 
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private :
        std::string const name;
        int grade;

    public :
        Bureaucrat();
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();

        Bureaucrat(std::string const &name, int grade);

        class GradeTooHighException : public std::exception {
            public :
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
                virtual const char *what() const throw();
        };

        void getName( void );
        void getGrade( void );

        void incrementGrade( void );
        void decrementGrade( void );
};

#endif