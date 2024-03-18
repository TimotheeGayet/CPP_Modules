#include "Bureaucrat.hpp"
#include "AForm.hpp"

void main_test()
{
    Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 1);
    AForm *form = new AForm("form", 1, 1);
    std::cout << *bureaucrat << std::endl;
    std::cout << *form << std::endl;
    try
    {
        form->beSigned(*bureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *form << std::endl;
    delete form;
    delete bureaucrat;
}