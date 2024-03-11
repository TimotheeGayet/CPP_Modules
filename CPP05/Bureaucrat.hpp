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
                ;
        };

        void getName( void );
        void getGrade( void );
}

#endif