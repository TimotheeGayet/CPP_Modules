#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *bureaucrat = new Bureaucrat("John", 1);

    try
    {
        Bureaucrat *bobby = new Bureaucrat("Bobby", -54);
        bobby->getGrade();
        delete bobby;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error : " << e.what() << '\n';
    }

    try
    {
        Bureaucrat *bobby = new Bureaucrat("Bobby", 48687);
        bobby->getGrade();
        delete bobby;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error : " << e.what() << '\n';
    }

    std::cout << *bureaucrat << std::endl;

    while (1) {
        try {
            bureaucrat->decrementGrade();
            std::cout << *bureaucrat << std::endl;
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            break;
        }
    }
    while (1) {
        try {
            bureaucrat->incrementGrade();
            std::cout << *bureaucrat << std::endl;
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            break;
        }
    }

    delete bureaucrat;

    return 0;
}