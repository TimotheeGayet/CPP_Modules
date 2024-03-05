#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void ) {
    ClapTrap clapTrap("CT", 100, 100, 30);
    ScavTrap scavTrap("ST", 100, 50, 20);
    FragTrap fragTrap("FT", 100, 100, 30);
    
    std::cout << std::endl;

    clapTrap.attack("target");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(10);

    std::cout << std::endl;

    scavTrap.attack("target");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();

    std::cout << std::endl;

    fragTrap.attack("target");
    fragTrap.takeDamage(10);
    fragTrap.beRepaired(10);
    fragTrap.highFivesGuys();

    std::cout << std::endl;

    return 0;
}