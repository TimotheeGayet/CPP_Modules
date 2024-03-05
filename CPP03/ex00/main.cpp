#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
    ClapTrap jean("jean", 100, 100, 10);
    ClapTrap bob("bob", 100, 100, 10);

    jean.attack("bob");
    bob.beRepaired(5);
    jean.takeDamage(10);
    jean.beRepaired(5);
    return 0;
}