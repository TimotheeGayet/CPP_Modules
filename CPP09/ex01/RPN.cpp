#include "RPN.hpp"
#include <cstring>
#include <cstdlib>

RPN::RPN() {
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {
}

void RPN::add() {
    if (_stack.size() < 2)
        throw InvalidInputException();
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push(a + b);
}

void RPN::sub() {
    if (_stack.size() < 2)
        throw InvalidInputException();
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push(b - a);
}

void RPN::mul() {
    if (_stack.size() < 2)
        throw InvalidInputException();
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push(a * b);
}

void RPN::div() {
    if (_stack.size() < 2)
        throw InvalidInputException();
    double a = _stack.top();
    if (a == 0)
        throw DivisionByZeroException();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push(b / a);
}

void RPN::run(int argc, char **argv) {
    size_t i = 0;

    if (argc != 2)
        throw InvalidInputException();
    
    std::string input = argv[1];
    if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
        throw InvalidInputException();
    while (input[i]){
        while (input[i] == ' ')
            i++;
        if (isdigit(input[i]))
            this->_stack.push(strtod(input.c_str() + i, NULL));
        else {
            switch (input[i])
            {
                case '+':
                    add();
                    break;
                case '-':
                    sub();
                    break;
                case '*':
                    mul();
                    break;
                case '/':
                    div();
                    break;
                default:
                    throw InvalidInputException();
            }
        }
        if (input[++i] != ' ' && input[i])
            throw InvalidInputException();
    }
    if (_stack.size() != 1)
        throw InvalidInputException();
    std::cout << _stack.top() << std::endl;
}

const char *RPN::InvalidInputException::what() const throw() {
    return "Error: input: ./RPN \"<int> <int> <calc> <int> <calc> etc.\"";
}

const char *RPN::DivisionByZeroException::what() const throw() {
    return "DivisionByZeroException";
}