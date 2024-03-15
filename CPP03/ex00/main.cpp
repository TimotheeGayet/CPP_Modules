#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
    ClapTrap jean("jean");
    ClapTrap bob("bob");

    jean.attack("bob");
    bob.takeDamage(5);
    bob.beRepaired(5);
    jean.attack("bob");
    bob.takeDamage(10);
    jean.takeDamage(2);
    jean.beRepaired(5);
    return 0;
}