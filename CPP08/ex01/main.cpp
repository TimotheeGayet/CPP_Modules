#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(15000);
    for (int i = 0; i < 15000; i++) {
        try{
            sp.addNumber(rand());
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    return 0;
}