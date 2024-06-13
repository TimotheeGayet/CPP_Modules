#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <exception>
#include <cstdlib>

int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
        return 1;
    }

    try
    {
        // Convert input arguments to std::vector<int>
        std::vector<int> vec = PmergeMe::argvToContainer< std::vector<int> >(argv + 1);

        // Convert input arguments to std::deque<int>
        // std::deque<int> deq = PmergeMe::argvToContainer< std::deque<int> >(argv + 1);

        // Measure time to sort the vector
        clock_t start_vec = clock();
        PmergeMe::sortContainer< std::vector<int>, std::vector< std::pair<int, int> > >(vec);
        clock_t end_vec = clock();
        double duration_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;

        // Measure time to sort the deque
        // clock_t start_deq = clock();
        // PmergeMe::sortContainer< std::deque<int>, std::deque< std::pair<int, int> > >(deq);
        // clock_t end_deq = clock();
        // double duration_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1e6;

        // Output sorted vector
        std::cout << "Sorted vector: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        // Output sorted deque
        // std::cout << "Sorted deque: ";
        // for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        // {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;

        // Output the timing results
        std::cout << "Time to sort vector: " << duration_vec << " microseconds" << std::endl;
        // std::cout << "Time to sort deque: " << duration_deq << " microseconds" << std::endl;
    }
    catch (const PmergeMe::BadInputException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
