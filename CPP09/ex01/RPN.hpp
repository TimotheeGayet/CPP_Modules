#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private :
        std::stack<double> _stack;
    
    public :
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void add();
        void sub();
        void mul();
        void div();

        void run(int argc, char **argv);

        class InvalidInputException : public std::exception {
            public :
                virtual const char *what() const throw();
        };

        class DivisionByZeroException : public std::exception {
            public :
                virtual const char *what() const throw();
        };
};

#endif