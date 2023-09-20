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
    this->_grade = bc._grade;
    return *this;
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
    if (this->_grade <= 1)
    {
        throw (Bureaucrat::GradeTooHighException());
    }
    else
    {
        this->_grade--;
    }
}

void Bureaucrat::subtractGrade()
{
    if (this->_grade >= 150)
    {
        throw (Bureaucrat::GradeTooLowException());
    }
    else
    {
        this->_grade++;
    }
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because it's not signed" << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade can't be less than 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade can't be more than 150");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bc)
{
    os << bc.getName() << ", bureaucrat grade " << bc.getGrade() << std::endl;
    return os;
}