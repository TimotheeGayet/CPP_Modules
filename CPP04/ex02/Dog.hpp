#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
    private:
        Brain *brain;

    public:
        Dog(void);
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);
        ~Dog();

        void makeSound(void);
};

#endif