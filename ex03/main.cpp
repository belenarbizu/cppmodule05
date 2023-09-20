#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        PresidentialPardonForm PPF("Prueba Target");
        Bureaucrat bc1("Blue", 4);
        bc1.signForm(PPF);
        std::cout << PPF.isSigned() << std::endl;
        PPF.execute(bc1);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    try
    {
        RobotomyRequestForm RRF("Uno");
        Bureaucrat bc("Blue", 44);
        std::cout << RRF.isSigned() << std::endl;
        bc.signForm(RRF);
        RRF.execute(bc);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm SCF("Dos");
        Bureaucrat bc("Blue", 79);
        bc.signForm(SCF);
        SCF.execute(bc);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
