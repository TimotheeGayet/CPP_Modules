#include "Harl.hpp"

Harl::Harl() {
    return;
}

Harl::~Harl() {
    return;
}

void Harl::complain( std::string level ) {
    if (level == "debug") {
        debug();
    } else if (level == "error") {
        error();
    } else if (level == "info") {
        info();
    } else if (level == "warning") {
        warning();
    } else {
        std::cout << "Unknown level" << std::endl;
    }
    return;
}

void Harl::debug( void ) {
    std::cout << "Debug" << std::endl;
    return;
}