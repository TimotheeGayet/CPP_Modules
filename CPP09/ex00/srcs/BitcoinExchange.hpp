#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>

void parseLine(std::string &line);
void parseInputDate(std::string &input_date);
std::map<std::string, double> parseData(std::string const &data_filename);
void btcPriceFind(std::map<std::string, double> &data, std::string input_filename);

#endif
