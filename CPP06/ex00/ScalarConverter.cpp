#include "ScalarConverter.hpp"
#include <climits>
#include <stdio.h>
#include <math.h>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {(void)other;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    *this = other;
    return *this;
}

template<typename T>
void toChar(const T &value) {
    char c = static_cast<char>(value);
    if (isprint(c))
        std::cout << "char : '" << c << "'" << std::endl;
    else if (isnan(value) || isinf(value))
        std::cout << "char : impossible" << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
}

template<typename T>
void toInt(const T &value) {
    if (isnan(value) || isinf(value))
        std::cout << "int : impossible" << std::endl;
    else {
        int i = static_cast<int>(value);
        std::cout << "int : " << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
    }
}

template<typename T>
void toFloat(const T &value) {
    float f = static_cast<float>(value);
    std::cout << "float : " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
}

template<typename T>
void toDouble(const T &value) {
    double d = static_cast<double>(value);
    std::cout << "double : " << std::fixed << std::setprecision(2) << d << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    char *endp;
    double number = strtod(input.c_str(), &endp);
    if (input.length() == 1 && isascii(*endp) && !isdigit(input[0]) && isprint(*endp)) {
        toChar(*endp);
        toInt(*endp);
        toFloat(*endp);
        toDouble(*endp);
    }
    else if (!*endp && number <= INT_MAX && number >= INT_MIN && input.find('.') == std::string::npos) {
        toChar(atoi(input.c_str()));
        toInt(atoi(input.c_str()));
        toFloat(atoi(input.c_str()));
        toDouble(atoi(input.c_str()));
    }
    else if (*endp == 'f' && input.length() > 1  && ((number <= MAXFLOAT && number >= (MAXFLOAT * -1)) || (isnan(number) || isinf(number)))) {
        toChar(strtof(input.c_str(), NULL));
        toInt(strtof(input.c_str(), NULL));
        toFloat(strtof(input.c_str(), NULL));
        toDouble(strtof(input.c_str(), NULL));
    }
    else if (!*endp) {
        toChar(number);
        toInt(number);
        toFloat(number);
        toDouble(number);
    }
}
