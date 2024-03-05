#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &Dog) : AAnimal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = Dog;
}

Dog &Dog::operator=(const Dog &Dog)
{
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = Dog.type;
    this->brain = new Brain(*Dog.brain);
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
    return;
}

void Dog::makeSound(void)
{
    std::cout << "**WOUF WOUF**" << std::endl;
}