#include "PmergeMe.hpp"
#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe [list of numbers]" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    // Check
    try
    {
        vec = PmergeMe::convertToContainer<std::vector<int>>(static_cast<const char **>(argv++));
        deq = PmergeMe::convertToContainer<std::deque<int>>(static_cast<const char **>(argv++));
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::cout << "Before : ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::clock_t start;
    double duration;
    start = std::clock();
    PmergeMe::sortContainer<std::vector<int>>(vec);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    std::cout << "After : ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << duration << "s" << std::endl;

    start = std::clock();
    PmergeMe::sortContainer<std::deque<int>>(deq);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << duration << "s" << std::endl;

    return 0;
}
