#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHp(_hitPoints) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string & name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHp(_hitPoints) {
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_maxHp = other._maxHp;
    return *this;
}

void    ClapTrap::isDead(const std::string & arg) {
    if (this->_hitPoints <= 0) 
        std::cout << "ClapTrap " << this->_name << " is already dead, he can't " << arg << " !" << std::endl;
    else if (this->_energyPoints <= 0)
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy to " << arg << " !" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints && this->_hitPoints){
        this->_energyPoints --;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else
        isDead("attack");
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->_hitPoints -= amount;
        if (this->_hitPoints <= 0) {
            this->_hitPoints = 0;
            std::cout << "ClapTrap " << this->_name << " is DEAD !" << std::endl;
        }
    } else 
        isDead("take damage");
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints && this->_hitPoints) {
        std::cout << "ClapTrap " << this->_name << " has repaired a total of " << amount << " points!" << std::endl;
        this->_hitPoints += amount;
        if (this->_hitPoints >= this->_maxHp) {
            this->_hitPoints = this->_maxHp;
            std::cout << "ClapTrap " << this->_name << " is fully repaired !" << std::endl;
        }
    } else
        isDead("repair himself");
}
