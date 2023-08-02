#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
    {
        throw (Bureaucrat::GradeTooLowException());
    }
    else if (grade < 1)
    {
        throw (Bureaucrat::GradeTooHighException());
    }
    else
    {
        this->_grade = grade;
        std::cout << "Bureaucrat constructor called" << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bc)
{
    *this = bc;
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& bc)
{

}

const std::string Bureaucrat::getName()
{
    return (this->_name);
}

int Bureaucrat::getGrade()
{
    return (this->_grade);
}

void Bureaucrat::addGrade()
{

}

void Bureaucrat::subtractGrade()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade can't be less than 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade can't be more than 150");
}