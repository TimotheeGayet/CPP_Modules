#include "Data.hpp"
#include <stdio.h>

Data::Data() : s1("default") {}

Data::Data(Data const &other){
    *this = other;
}

Data &Data::operator=(Data const &other) {
    if (this != &other)
        s1 = other.s1;
    return *this;
}

Data::~Data() {}