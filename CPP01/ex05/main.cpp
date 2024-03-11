#include "Harl.hpp"

int main( void ) {
    Harl harl;

    std::cout << "Harl Debug :"; harl.complain("DEBUG"); std::cout << std::endl;
    std::cout << "Harl Info :"; harl.complain("INFO"); std::cout << std::endl;
    std::cout << "Harl Warning :"; harl.complain("WARNING"); std::cout << std::endl;
    std::cout << "Harl Error :"; harl.complain("ERROR"); std::cout << std::endl;
    return 0;
}