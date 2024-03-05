#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "---------------------------------------------" << std::endl;
    Dog *dog = new Dog();
    std::cout << "---------------------------------------------" << std::endl;
    Cat *cat = new Cat();
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "dog->getType() : " << dog->getType() << std::endl;
    std::cout << "cat->getType() : " << cat->getType() << std::endl;
    std::cout << "cat->makeSound() : ";
    cat->makeSound();
    std::cout << "dog->makeSound() : ";
    dog->makeSound();
    std::cout << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    delete dog;
    std::cout << "---------------------------------------------" << std::endl;
    delete cat;

    return 0;
}