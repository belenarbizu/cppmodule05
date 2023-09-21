#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern& intern);
    Intern& operator=(const Intern& intern);

    AForm* ShrubberyCreation(std::string target);
    AForm* RobotomyRequest(std::string target);
    AForm* PresidentialPardon(std::string target);

    AForm* makeForm(std::string form, std::string target);
};

#endif