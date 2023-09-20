#ifndef SHUBBERYCREATIONFORM_HPP
#define SHUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(const ShrubberyCreationForm& shrub);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrub);

    virtual void	execute(Bureaucrat const & executor) const;
};

#endif