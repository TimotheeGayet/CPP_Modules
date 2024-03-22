#include "ScalarConverter.hpp"
#include <stdlib.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {(void)other;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    *this = other;
    return *this;
}

void ScalarConverter::convert(std::string input)
{
    char *endp;
    strtod(input.c_str(), &endp);
    std::cout << *endp << std::endl;
}
