#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(){
    ClapTrap clapTrap("ClapTrap");
    ScavTrap scavTrap("ScavTrap");
    FragTrap fragTrap("FragTrap");

    clapTrap.attack("ScavTrap");
    scavTrap.takeDamage(0);
    scavTrap.beRepaired(5);

    scavTrap.attack("ClapTrap");
    clapTrap.takeDamage(20);
    clapTrap.beRepaired(5);

    scavTrap.guardGate();

    fragTrap.attack("ScavTrap");
    scavTrap.takeDamage(20);
    fragTrap.highFivesGuys();

    return 0;
}