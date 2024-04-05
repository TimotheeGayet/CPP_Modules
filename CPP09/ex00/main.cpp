#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Error: usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    Data data;

    if (!data.parseData("data.csv")) {
        return 1;
    }

    std::ifstream input(argv[1]);

    if (!input.is_open()) {
        std::cout << "Error: cannot open file " << argv[1] << std::endl;
        return 1;
    }

    try
    {
        if (!data.btcPriceCompare(input))
            return 1;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

    return 0;
}