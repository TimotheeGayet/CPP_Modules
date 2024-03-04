#include "File.hpp"
#include <fstream>

File::File( std::ofstream& outfile, std::ifstream& infile, std::string content ) : outfile(outfile), infile(infile), content(content) {
    return ;
}

File::~File( void ) {
    return ;
}

void File::updateFile( std::string old_str, std::string new_str ) {
    std::string line;
    while (std::getline(infile, line)) {
        size_t pos = line.find(old_str);
        while (pos != std::string::npos) {
            line = line.substr(0, pos) + new_str + line.substr(pos + old_str.length());
            pos = line.find(old_str, pos + new_str.length());
        }
        outfile << line << std::endl;
    }
    return ;
}