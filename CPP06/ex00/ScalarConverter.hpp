#ifndef SCALARCONVERTER_HPP
#define SCSCALARCONVERTER_HPPALARCONVERTER_HPP

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