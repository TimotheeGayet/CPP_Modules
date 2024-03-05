#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal constructor called" << std::endl;
    this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &aanimal)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = aanimal;
}

AAnimal &AAnimal::operator=(const AAnimal &aanimal)
{
    std::cout << "AAnimal assignation operator called" << std::endl;
    this->type = aanimal.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
    return;
}

std::string AAnimal::getType(void)
{
    return this->type;
}