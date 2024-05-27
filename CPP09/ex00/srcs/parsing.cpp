#include "BitcoinExchange.hpp"

std::map<Date, double> parseData(std::string const &data_filename)
{
	fstream file(data_filename);
	std::map<Date, double> data;
	std::string line;

	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file");
	}

	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		throw std::runtime_error("Error: invalid file format");
	}

	while (std::getline(file, line))
	{
		std::string date;
		std::string price;
		int day, month, year;

		date = line.substr(0, line.find(','));
		price = line.substr(line.find(',') + 1);
		day = std::stoi(date.substr(0, date.find('/')));
		month = std::stoi(date.substr(date.find('/') + 1, date.rfind('/') - date.find('/') - 1));
		year = std::stoi(date.substr(date.rfind('/') + 1));
		Date d(year, month, day);
		data[d] = std::stod(price);
	}

	if (data.empty())
	{
		throw std::runtime_error("Error: no data");
	}

	return data;
}
