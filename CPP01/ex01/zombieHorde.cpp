#include "Zombie.hpp"
#include <iostream>

int isAlpha(std::string str)
{
    for (int i = 0; str[i]; i++)
        if (!isalpha(str[i]))
            return 1;
    return 0;
}

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0 || N > 1000) {
        std::cout << "Error : Number of zombies must be between 1 and 1000" << std::endl;
        return NULL;
    }
    if (name.empty() || name.length() > 20 || isAlpha(name)){
        std::cout << "Error : Name must not be empty, longer than 20 characters and alpha only" << std::endl;
        return NULL;
    }
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].changeName(name);
    return horde;
}