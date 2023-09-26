#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    std::cout << "--------------PPF HULK----------------" << std::endl;
    try
    {
        PresidentialPardonForm PPF("Hulk");
        Bureaucrat Blue("Blue", 4);
        Blue.signForm(PPF);
        PPF.execute(Blue);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------RRF UNO---------------" << std::endl;
    try
    {
        RobotomyRequestForm RRF("Uno");
        Bureaucrat bc2("Green", 44);
        RRF.beSigned(bc2);
        RRF.execute(bc2);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------SCF BART---------------" << std::endl;
    try
    {
        ShrubberyCreationForm SCF("Bart");
        Bureaucrat bc3("Red", 79);
        bc3.signForm(SCF);
        SCF.execute(bc3);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------COULDN'T SIGN--------------" << std::endl;
    try
    {
        PresidentialPardonForm PPF("Gus");
        Bureaucrat Blue("Blue", 44);
        Blue.signForm(PPF);
        PPF.execute(Blue);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------GRADE TOO LOW---------------" << std::endl;
    try
    {
        RobotomyRequestForm RRF("Low");
        Bureaucrat bc2("Green", 50);
        RRF.beSigned(bc2);
        RRF.execute(bc2);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
