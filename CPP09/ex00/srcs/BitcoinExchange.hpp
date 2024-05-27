#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include "./Date/Date.hpp"

std::map<Date, double> parseData(std::string const &data_filename);

#endif
