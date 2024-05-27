#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bitcoin [data_filename]" << std::endl;
		return 1;
	}

	std::map<Date, double> data;
	try
	{
		data = parseData(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
