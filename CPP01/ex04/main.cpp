#include <iostream>
#include <fstream>
#include "File.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Invalid number of arguments" << std::endl;
        return 1;
    }
    if (argv[2][0] == '\0' || argv[3][0] == '\0') {
        std::cout << "Invalid string" << std::endl;
        return 1;
    }
    std::string infile = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string outfile_name = infile + ".replace";

    std::ifstream ifs (infile.c_str(), std::ifstream::in);
    if (!ifs.is_open()) {
        std::cout << "Could not open File " << infile << std::endl;
        return 1;
    }

    std::ofstream ofs (outfile_name.c_str(), std::ofstream::out);
    if (!ofs.is_open()) {
        std::cout << "File " << infile + ".replace" << " could not be created" << std::endl;
        ifs.close();
        return 1;
    }

    File file(ofs, ifs, s1);

    file.replaceInFile( s1, s2 );

    ifs.close();
    ofs.close();

    return 0;
    
}