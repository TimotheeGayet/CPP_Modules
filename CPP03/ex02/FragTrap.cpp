#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap " << _name << " is born !" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_maxHp = 100;
    std::cout << "FragTrap " << _name << " is born with parameters !" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_maxHp = other._maxHp;
    std::cout << "ScavTrap " << _name << " is born by copy !" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_maxHp = other._maxHp;
    return *this;
    std::cout << "ScavTrap " << _name << " is born by assignation !" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_energyPoints && this->_hitPoints){
        this->_energyPoints --;
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else
        isDead("attack");
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " wants to high five !" << std::endl;
}