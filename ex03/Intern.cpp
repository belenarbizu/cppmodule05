#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}
Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}
Intern::Intern(const Intern& intern)
{
    *this = intern;
    std::cout << "Copy constructor called" << std::endl;
}
Intern& Intern::operator=(const Intern& intern)
{
    (void)intern;
    return *this;
}

AForm* Intern::ShrubberyCreation(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::RobotomyRequest(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::PresidentialPardon(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    AForm* (Intern::*newForm[3])(std::string target) = {&Intern::RobotomyRequest, &Intern::PresidentialPardon, &Intern::ShrubberyCreation};

    for (int i = 0; i < 3; i++)
    {
        if (form == formNames[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return ((this->*newForm[i])(target));
        }
    }
    std::cout << "Form doesn't exist" << std::endl;
    return NULL;
}