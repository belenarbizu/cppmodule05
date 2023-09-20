#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 72, 45), _target("Anonymous")
{
    std::cout << "RRF constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), _target(target)
{
    std::cout << "RRF constructor called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RRF destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robot) :  AForm(robot.getName(), robot.getSignGrade(), robot.getExecGrade()), _target(robot._target)
{
    std::cout << "RRF copy constructor called" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robot)
{
    this->_target = robot._target;
    return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    canBeExecutable(executor);
    if (std::rand() % 2 == 0)
    {
        std::cout << this->_target << " has been robotomized" << std::endl;
    }
    else
    {
        std::cout << this->_target << " hasn't been robotomized" << std::endl;
    }
}