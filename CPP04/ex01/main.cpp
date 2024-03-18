#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Dog *a = new Dog();
    Dog *b = new Dog(*a);

    (void)b;

    delete a;
    delete b;

    // const Animal *animals[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << i + 1 << "------------------------------------------" << std::endl;
    //     if (i % 2 == 0)
    //         animals[i] = new Dog();
    //     else
    //         animals[i] = new Cat();
    // }

    // std::cout << "------------------------------------------\n\n" << std::endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << i + 1 << "------------------------------------------" << std::endl;
    //     animals[i]->makeSound();
    // }

    // std::cout << "------------------------------------------\n\n" << std::endl;
    
    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << i + 1 << "------------------------------------------" << std::endl;
    //     delete animals[i];
    // }
    return 0;
}