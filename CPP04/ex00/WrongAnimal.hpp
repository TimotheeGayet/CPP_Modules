#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
        virtual ~WrongAnimal();

        void makeSound(void) const;
        std::string getType(void) const;
};

#endif