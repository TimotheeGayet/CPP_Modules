#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *animal = new Animal();
    std::cout << "---------------------------------------------" << std::endl;
    const Animal *dog = new Dog();
    std::cout << "---------------------------------------------" << std::endl;
    const Animal *cat = new Cat();
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "dog->getType() : " << dog->getType() << std::endl;
    std::cout << "cat->getType() : " << cat->getType() << std::endl;
    std::cout << "cat->makeSound() : ";
    cat->makeSound();
    std::cout << "dog->makeSound() : ";
    dog->makeSound();
    std::cout << "animal->makeSound() : ";
    animal->makeSound();
    std::cout << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    delete animal;
    std::cout << "---------------------------------------------" << std::endl;
    delete dog;
    std::cout << "---------------------------------------------" << std::endl;
    delete cat;

    std::cout << "\n---------------------WrongAnimal Tests---------------------\n" << std::endl;

    const WrongAnimal *wrongAnimal = new WrongAnimal();
    std::cout << "---------------------------------------------" << std::endl;
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "wrongCat->getType() : " << wrongCat->getType() << " " << std::endl;
    std::cout << "wrongCat->makeSound() : ";
    wrongCat->makeSound();
    std::cout << "wrongAnimal->makeSound() : ";
    wrongAnimal->makeSound();
    std::cout << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    delete wrongAnimal;
    std::cout << "---------------------------------------------" << std::endl;
    delete wrongCat;

    return 0;
}