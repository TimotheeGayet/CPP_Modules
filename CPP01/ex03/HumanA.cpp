#include "HumanA.hpp"

HumanA::HumanA( std::string str, Weapon &weapon ) : _name(str), _weapon(weapon) {}

HumanA::~HumanA( void ) {}

void HumanA::attack( void ) {
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
