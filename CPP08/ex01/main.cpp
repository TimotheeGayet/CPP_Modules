#include "Span.hpp"
#include <iostream>
#include <vector>

#define CONTAINER_SIZE 10

int main() {
    Span sp = Span(CONTAINER_SIZE);
    for (int i = 0; i < CONTAINER_SIZE; i++)
    {
        try
        {
            int nbr = std::rand() % 100;
            std::cout << "nbr:" << nbr << std::endl;
            sp.addNumber(nbr);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;

    return 0;
}