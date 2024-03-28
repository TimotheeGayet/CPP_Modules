#include "Data.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Private constructor

Data::Data() {
    _data = std::map<std::string, double>();
}

Data::Data(const Data &other) {
    _data = other._data;
}

Data &Data::operator=(const Data &other) {
    _data = other._data;
    return *this;
}

// Constructor/Destructor

#include <sstream>

Data::Data(std::ifstream &file) {
    _data = std::map<std::string, double>();
    std::string line;
    while (std::getline(file, line)) {
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        
        std::istringstream iss(value);
        double doubleValue;
        iss >> doubleValue;
        if (key != "date")
            _data[key] = doubleValue;
    }
}

Data::~Data() {
}

// Public methods

std::map<std::string, double> Data::getData() {
    return _data;
}

void Data::printData() {
    for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++) {
        std::cout << '|' << it->first << '|' << " = " << '|' << it->second << '|' << std::endl;
    }
}