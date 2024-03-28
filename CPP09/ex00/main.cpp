#include "Data.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (!parsing(argc, argv))
        return 1;
    std::ifstream file("data.csv");
    Data data(file);
    return 0;
}