#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 145, 137), _target("Anonymous")
{
    std::cout << "SCF constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), _target(target)
{
    std::cout << "SCF constructor called" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "RRF destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrub) : AForm(shrub.getName(), shrub.getSignGrade(), shrub.getExecGrade()), _target(shrub._target)
{
    std::cout << "SCF copy constructor called" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrub)
{
    this->_target = shrub._target;
    return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    canBeExecutable(executor);
    std::string fileName = this->_target + "_shrubbery";
    std::ofstream file(fileName, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Can't create the file" << std::endl;
    }
    else
    {
        file << "    *\n"
                "   ***\n"
                "  *****\n"
                " *******\n"
                "*********\n"
                "    ¬¬    \n";
        file.close();
    }
}