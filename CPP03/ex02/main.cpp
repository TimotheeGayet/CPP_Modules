#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clapTrap("ClapTrap");
    ScavTrap scavTrap("ScavTrap");

    clapTrap.attack("ScavTrap");
    scavTrap.takeDamage(0);
    scavTrap.beRepaired(5);

    scavTrap.attack("ClapTrap");
    clapTrap.takeDamage(30);
    clapTrap.beRepaired(5);

    scavTrap.guardGate();

    return 0;
}