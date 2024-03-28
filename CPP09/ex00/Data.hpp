#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <map>

class Data {
    private :
        Data();
        Data(const Data &other);
        Data &operator=(const Data &other);
        std::map<std::string, double> _data;

    public :
        Data(std::ifstream &file);
        ~Data();
        std::map<std::string, double> getData();
        void printData();
};

int parsing(int argc, char **argv);

#endif