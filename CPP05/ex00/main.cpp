#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *bureaucrat = new Bureaucrat("John", 150);

    bureaucrat->getName();
    bureaucrat->getGrade();

    while (1) {
        try {
            bureaucrat->decrementGrade();
            bureaucrat->getGrade();
        } catch (Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Error : Grade is too low, below 150" << std::endl;
            break;
        } catch (Bureaucrat::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
            break;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            break;
        }
    }

    delete bureaucrat;

    return 0;
}