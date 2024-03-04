#include "HumanA.hpp"

HumanA::HumanA( std::string str, Weapon &weapon ) : name(str), weapon(weapon) {
    return;
}

HumanA::~HumanA( void ) {
    return;
}

void HumanA::attack( void ) {
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
