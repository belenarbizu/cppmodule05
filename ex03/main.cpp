#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
        delete ppf;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        delete scf;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* wrongForm;
        wrongForm = someRandomIntern.makeForm("WorngForm", "Bender");
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
