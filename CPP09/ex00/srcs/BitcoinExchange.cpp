#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

void parseLine(std::string &line)
{
	if (line.find('|') == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
	}

	int amount = std::stoi(line.substr(line.find('|') + 1));

	if (amount < 0 || amount > 1000)
	{
		std::cout << "Error: bad input => " << line << std::endl;
	}
}

void btcPriceFind(std::map<Date, double> &data, std::string input_filename)
{
	fstream file(input_filename);
	std::string line;

	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file");
	}

	std::getline(file, line);

	if (line == "date | value")
	{
		std::getline(file, line);
	}

	while (line != "" && !file.eof())
	{
		std::string input_date;
		double amount;
		int day, month, year;

		if (line.find('|') == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}

		input_date = line.substr(0, line.find('|'));
		amount = stod(line.substr(line.find('|') + 1));
		day = std::stoi(input_date.substr(0, input_date.find('-')));
		month = std::stoi(input_date.substr(input_date.find('-') + 1, input_date.rfind('-') - input_date.find('-') - 1));
		year = std::stoi(input_date.substr(input_date.rfind('-') + 1));

		Date d(year, month, day);
		while (data.find(d) == data.end() && d.getYear() >= 2009)
		{
			d--;
		}

		if (d.getYear() < 2009)
		{
			std::cout << input_date << " => " << amount << " = 0" << std::endl;
		}
		else
		{
			std::cout << input_date << " => " << amount << " = " << data[d] * amount << std::endl;
		}

		std::getline(file, line);
	}
}
