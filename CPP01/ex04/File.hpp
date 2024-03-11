#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>

class File {
    public:
        File( std::ofstream& outfile, std::ifstream& infile, std::string content );
        ~File();
        
        void replaceInFile( std::string old_str, std::string new_str );

    private:
        std::ofstream& outfile;
        std::ifstream& infile;
        std::string content;
};

#endif