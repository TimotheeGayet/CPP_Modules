#include "BitcoinExchange.hpp"

void btcPriceFind(std::map<std::string, double> &data, std::string input_filename)
{
	std::ifstream file(input_filename.c_str());
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

	while (true)
	{
		std::string input_date;
		double value = 0;
		double amount = 0;

		try
		{
			parseLine(line);

			input_date = line.substr(0, line.find('|'));
			amount = strtod(line.substr(line.find('|') + 1).c_str(), NULL);

			input_date = input_date.substr(input_date.find_first_not_of(' '), input_date.find_last_not_of(' ') + 1);

			parseInputDate(input_date);

			if (input_date > data.rbegin()->first)
			{
				value = data.rbegin()->second;
			}
			else
			{
				for (std::map<std::string, double>::iterator it = data.begin(); it != data.end() && it->first <= input_date; it++)
				{
					value = it->second;
				}
			}

			std::cout << input_date << " => " << amount << " = " << value * amount << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		if (file.eof())
		{
			break;
		}
		std::getline(file, line);
	}
}
