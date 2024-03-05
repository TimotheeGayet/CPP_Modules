#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap " << _name << " is born !" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
    std::cout << "ScavTrap " << _name << " is born with parameters !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " is born by copy !" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is dead !" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode !" << std::endl;
}