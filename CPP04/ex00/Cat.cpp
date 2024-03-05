#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &cat) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = cat.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    return;
}

void Cat::makeSound(void) const
{
    std::cout << "**Meow Meow**" << std::endl;
}