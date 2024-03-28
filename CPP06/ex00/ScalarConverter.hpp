#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ~ScalarConverter();
        ScalarConverter &operator=(ScalarConverter const &other);

    public:

        static void convert(std::string input);
};

#endif