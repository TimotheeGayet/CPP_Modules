#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data {
    public :
        Data();
        Data(Data const &other);
        Data &operator=(Data const &other);
        ~Data();

        std::string s1;
};

#endif