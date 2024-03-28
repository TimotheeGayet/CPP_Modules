#include "Data.hpp"
#include <iostream>
#include <fstream>

int parsing(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: usage: " << argv[0] << " <file input>" << std::endl;
        return false;
    }

    std::string filename = argv[1];
    if (filename.empty()) {
        std::cerr << "Error: usage: " << argv[0] << " <file input>" << std::endl;
        return false;
    }

    std ::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return false;
    }

    while (std::getline(file, std::string line)) {
        std::cout << line << std::endl;
    }

    return true;
}