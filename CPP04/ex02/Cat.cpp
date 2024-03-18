#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : AAnimal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = cat.type;
    *this->brain = *cat.brain;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
    return;
}

void Cat::makeSound(void)
{
    std::cout << "**Meow Meow**" << std::endl;
}