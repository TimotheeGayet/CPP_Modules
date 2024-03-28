#include "Iter.hpp"
#include <iostream>

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};

    std::cout << "Int array:" << std::endl;
    iter(intArray, 5, print);
    std::cout << "Char array:" << std::endl;
    iter(charArray, 5, print);
    std::cout << "Float array:" << std::endl;
    iter(floatArray, 5, print);
    std::cout << "String array:" << std::endl;
    iter(stringArray, 5, print);
    
    return 0;
}