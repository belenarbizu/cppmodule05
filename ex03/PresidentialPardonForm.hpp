#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    PresidentialPardonForm(const PresidentialPardonForm& ppf);
    PresidentialPardonForm& operator= (const PresidentialPardonForm& ppf);

    virtual void	execute(Bureaucrat const & executor) const;
};

#endif