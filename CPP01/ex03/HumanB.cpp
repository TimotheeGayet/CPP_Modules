#include "HumanB.hpp"

HumanB::HumanB( std::string str ) : name(str) {
    return;
}

HumanB::~HumanB( void ) {
    return;
}

void HumanB::setWeapon( Weapon &weapon ) {
    this->weapon = &weapon;
}

void HumanB::attack( void ) {
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}
