#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cmath>
#include <cctype>

// constructor

Data::Data() {
    _data = std::map<std::string, double>();
}

Data::Data(const Data &other) {
    *this = other;
}

Data &Data::operator=(const Data &other) {
    _data = other._data;
    return *this;
}

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

bool Data::isNumeric(const std::string& str, int flag) {
    std::istringstream iss(str);
    double value;
    iss >> value;
    if (value < 0 && flag) {
        throw negativeNumber();
    }
    if (value > 1000 && flag) {
        throw tooLargeNumber();
    }
    return true;
}

bool Data::isValidDate(const std::string& date, const std::string& line) {
    int year, month, day;
    char dash;
    std::istringstream iss(date);
    iss >> year >> dash >> month >> dash >> day;
    if (iss.fail() || dash != '-' || month < 1 || month > 12 || year < 0) {
        throw badInput(line);
    }
    int dayPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        dayPerMonth[1] = 29;
    if (day < 1 || day > dayPerMonth[month - 1]) {
        throw badInput(line);
    }
    return true;
}

double Data::getBitcoinPrice(const std::string& date) {
    if (this->_data.find(date) != this->_data.end())
        return this->_data[date];
    std::istringstream dateStream(date);
    int year, month, day;
    char dash;
    dateStream >> year >> dash >> month >> dash >> day;
    if (day == 1) {
        if (month == 1) {
            year--;
            month = 12;
        } else {
            month--;
        }
        day = 31;
    } else {
        day--;
    }
    std::ostringstream newDateStream;
    newDateStream << year << '-' << (month < 10 ? "0" : "") << month << '-' << (day < 10 ? "0" : "") << day;
    return getBitcoinPrice(newDateStream.str());
}

bool Data::btcPriceCompare(std::istream& input) {
    std::string line;
    std::getline(input, line);
    if (line.empty() || line != "date | value")
        return false;
    while (std::getline(input, line)) {
        std::istringstream lineStream(line);
        std::string date, amount;
        try
        {
            std::getline(lineStream, date, '|');
            std::getline(lineStream, amount);
            isNumeric(amount, 1);
            isValidDate(date, line);
            std::cout << date.substr(0, date.length() - 1) << " =>" << amount << " = " << (getBitcoinPrice(date.substr(0, date.length() - 1)) * strtod(amount.c_str(), NULL)) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    return true;
}

bool Data::parseData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file || !file.is_open()) {
        std::cout << "Error: cannot open file " << filename << std::endl;
        return false;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string date, exchangeRate;
        if (std::getline(lineStream, date, ',') && std::getline(lineStream, exchangeRate) &&
            isNumeric(exchangeRate, 0) && isValidDate(date, line))
            this->_data[date] = strtod(exchangeRate.c_str(), NULL);
        else {
            std::cout << "Error: Invalid format in data file : " << "\"" << line << "\"" << std::endl;
            return false;
        }
    }
    return true;
}

// Error handling

const char* Data::negativeNumber::what() const throw() {
    return "Error: not a positive number.";
}

const char* Data::badInput::what() const throw() {
    std::cout << "Error: bad input => " << this->_line;
    return "";
}

const char* Data::tooLargeNumber::what() const throw() {
    return "Error: too large number.";
}