#include "HumanB.hpp"

HumanB::HumanB( std::string str ) :_name(str), _weapon(NULL) {}

HumanB::~HumanB( void ) {}

void HumanB::setWeapon( Weapon &weapon ) {
    this->_weapon = &weapon;
}

void HumanB::attack( void ) {
    if (_weapon == NULL)
        std::cout << _name << " attacks with his bare hands " << std::endl;
    else
        std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}
