#include "Array.hpp"
#include <iostream>
#include <sstream>

int main() {
    Array<int> a(5);
    Array<std::string> b(5);

    for (unsigned int i = 0; i < a.size(); i++) {
        a[i] = i;
        std::stringstream ss;
        ss << i;
        b[i] = "number" + ss.str();
    }

    for (unsigned int i = 0; i < a.size(); i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    try {
        a[5] = 42;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}