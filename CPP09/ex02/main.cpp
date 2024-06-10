#include "Pmergeme.hpp"
#include <algorithm>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./PmergeMe 1 2 3 4 5 6 7 8 9 10" << std::endl;
        return 1;
    }
    argv += 1;
    std::vector<int> container = PmergeMe::convertToContainer(argv);
}
