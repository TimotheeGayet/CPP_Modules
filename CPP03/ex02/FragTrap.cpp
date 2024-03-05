#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap " << _name << " is born !" << std::endl;
}

FragTrap::FragTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
    std::cout << "FragTrap " << _name << " is born with parameters !" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " is born by copy !" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " is dead !" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " wants to high five !" << std::endl;
}