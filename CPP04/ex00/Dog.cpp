#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &Dog) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = Dog;
}

Dog &Dog::operator=(const Dog &Dog)
{
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = Dog.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    return;
}

void Dog::makeSound(void) const
{
    std::cout << "**Ouaf Ouaf**" << std::endl;
}