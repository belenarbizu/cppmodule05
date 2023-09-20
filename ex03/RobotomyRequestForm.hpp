#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm& robot);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& robot);

    virtual void	execute(Bureaucrat const & executor) const;
};

#endif