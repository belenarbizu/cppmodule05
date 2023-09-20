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

bool AForm::getSigned() const
{
    return (this->_signed);
}

void AForm::beSigned(Bureaucrat bc)
{
    if (bc.getGrade() <= this->_signGrade)
        this->_signed = true;
    else
        throw (AForm::GradeTooLowException());
}

int AForm::isSigned() const
{
    if (this->_signed)
        return 1;
    return 0;
}
void AForm::canBeExecutable(Bureaucrat const & bc) const
{
    if (!this->_signed)
    {
        throw (AForm::IsNotSignedException());
    }
    if (this->_execGrade < bc.getGrade())
    {
        throw (AForm::GradeTooLowException());
    }
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* AForm::IsNotSignedException::what() const throw()
{
    return ("AForm is not signed");
}

std::ostream& operator<<(std::ostream& os, AForm& form)
{
    os << form.getName() << ", form sign grade " << form.getSignGrade() << " and execute grade " << form.getExecGrade() << std::endl;
    return os;
}