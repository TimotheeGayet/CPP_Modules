#include "BitcoinExchange.hpp"

bool isBisextile(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

void parseInputDate(std::string &input_date)
{

	if (input_date.find('-') == std::string::npos ||
		input_date.find_first_of('-') == input_date.find_last_of('-'))
	{
		throw std::runtime_error("Error: bad input => " + input_date);
	}

	std::string year = input_date.substr(0, input_date.find('-'));
	std::string month = input_date.substr(input_date.find('-') + 1, input_date.find_last_of('-') - input_date.find('-') - 1);
	std::string day = input_date.substr(input_date.find_last_of('-') + 1);

	if (year.empty() || month.empty() || day.empty() ||
		year.find_first_not_of("0123456789") != std::string::npos ||
		month.find_first_not_of("0123456789") != std::string::npos ||
		day.find_first_not_of("0123456789") != std::string::npos)
	{
		throw std::runtime_error("Error: invalid date");
	}

	int is_bisextile = isBisextile(atoi(year.c_str()));
	int days_in_month[12] = {31, 28 + is_bisextile, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
	{
		throw std::runtime_error("Error: invalid date");
	}

	if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > days_in_month[atoi(month.c_str()) - 1])
	{
		throw std::runtime_error("Error: invalid date");
	}
}

void parseLine(std::string &line)
{
	if (line == "")
	{
		throw std::runtime_error("Error: empty line.");
	}

	if (line.find('|') == std::string::npos || line.find_first_of('|') != line.find_last_of('|'))
	{
		throw std::runtime_error("Error: bad input => " + line);
	}

	long amount = strtol(line.substr(line.find('|') + 1).c_str(), NULL, 10);

	if (amount == 0 && line.substr(line.find('|') + 1) != "0")
	{
		throw std::runtime_error("Error: amount is not a number.");
	}

	if (amount < 0)
	{
		throw std::runtime_error("Error: not a positive number.");
	}
	if (amount > 1000)
	{
		throw std::runtime_error("Error: too large a number.");
	}
}

std::map<std::string, double> parseData(std::string const &data_filename)
{
	std::ifstream file(data_filename.c_str());
	std::map<std::string, double> data;
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
		std::string date = line.substr(0, line.find(','));
		std::string price = line.substr(line.find(',') + 1);

		date = date.substr(date.find_first_not_of(' '), date.find_last_not_of(' ') + 1);
		price = price.substr(price.find_first_not_of(' '), price.find_last_not_of(' ') + 1);

		if (date.empty() || price.empty() ||
			date.find_first_not_of("0123456789-") != std::string::npos ||
			price.find_first_not_of("0123456789.") != std::string::npos)
		{
			throw std::runtime_error("Error: invalid data");
		}

		if (data.find(date) != data.end())
		{
			throw std::runtime_error("Error: duplicate date");
		}

		data[date] = strtod(price.c_str(), NULL);
	}

	if (data.empty())
	{
		throw std::runtime_error("Error: no data");
	}

	return data;
}
