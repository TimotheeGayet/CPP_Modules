#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap " << _name << " is born !" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_maxHp = 100;
    std::cout << "ScavTrap " << _name << " is born with parameters !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " is born by copy !" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_maxHp = other._maxHp;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints && this->_hitPoints){
        this->_energyPoints --;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else
        isDead("attack");
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode !" << std::endl;
}