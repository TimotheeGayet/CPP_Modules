#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap( void );
        ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
        ClapTrap& operator=(const ClapTrap &other);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();

        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif