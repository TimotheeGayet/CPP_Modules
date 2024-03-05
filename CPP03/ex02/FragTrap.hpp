#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage);
        FragTrap(const FragTrap& other);
        ~FragTrap();
        FragTrap& operator=(const FragTrap &other);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif