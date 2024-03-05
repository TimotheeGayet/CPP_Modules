#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal &aanimal);
        AAnimal &operator=(const AAnimal &aanimal);
        virtual ~AAnimal();

        virtual void makeSound(void) = 0;
        std::string getType(void);
};

#endif