#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
    #include <vector>

    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    try {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}