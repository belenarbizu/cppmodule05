#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signGrade(150), _execGrade(150)
{
    this->_signed = false;
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    this->_signed = false;
    if (signGrade > 150 || execGrade > 150)
    {
        throw (AForm::GradeTooLowException());
    }
    else if (signGrade < 1 || signGrade < 1)
    {
        throw (AForm::GradeTooHighException());
    }
    else
    {
        std::cout << "AForm constructor called" << std::endl;
    }
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& form) : _name(form.getName()), _signGrade(form.getSignGrade()), _execGrade(form.getExecGrade())
{
    *this = form;
    std::cout << "Copy constructor called" << std::endl;
}

AForm& AForm::operator= (const AForm& form)
{
    this->_signed = form._signed;
    return *this;
}

const std::string AForm::getName() const
{
    return (this->_name);
}

int AForm::getSignGrade() const
{
    return (this->_signGrade);
}

int AForm::getExecGrade() const
{
    return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat bc)
{
    if (bc.getGrade() <= this->_signGrade)
        this->_signed = true;
    else
        throw (AForm::GradeTooLowException());
}

int AForm::isSigned()
{
    if (this->_signed)
        return 1;
    return 0;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade can't be less than 1");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade can't be more than 150");
}

std::ostream& operator<<(std::ostream& os, AForm& form)
{
    os << form.getName() << ", form sign grade " << form.getSignGrade() << " and execute grade " << form.getExecGrade() << std::endl;
    return os;
}