#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 25, 5), _target("Anonymous")
{
    std::cout << "PPF constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5), _target(target)
{
    std::cout << "PPF constructor called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PPF destructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) : AForm(ppf.getName(), ppf.getSignGrade(), ppf.getExecGrade()), _target(ppf._target)
{
    std::cout << "PPF copy constructor called" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& ppf)
{
    this->_target = ppf._target;
    return *this;
}
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    canBeExecutable(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}