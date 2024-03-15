#include "Animal.hpp"

Animal::Animal(void){
    std::cout << "Animal constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &animal){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal){
    std::cout << "Animal assignation operator called" << std::endl;
    this->type = animal.type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const{
    std::cout << "**Animal sound**" << std::endl;
}

std::string Animal::getType(void) const{
    return this->type;
}