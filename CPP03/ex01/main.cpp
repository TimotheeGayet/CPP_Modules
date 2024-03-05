#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
    ClapTrap clap("Clap", 10, 10, 10);
    ScavTrap scav("Scav", 10, 10, 10);

    clap.attack("Scav");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    return 0;
}