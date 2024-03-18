#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif