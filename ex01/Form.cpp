#include "Form.hpp"

Form::Form() : _name("Form"), _signGrade(150), _execGrade(150)
{
    this->_signed = false;
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    this->_signed = false;
    if (signGrade > 150 || execGrade > 150)
    {
        throw (Form::GradeTooLowException());
    }
    else if (signGrade < 1 || signGrade < 1)
    {
        throw (Form::GradeTooHighException());
    }
    else
    {
        std::cout << "Form constructor called" << std::endl;
    }
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& form) : _name(form.getName()), _signGrade(form.getSignGrade()), _execGrade(form.getExecGrade())
{
    *this = form;
    std::cout << "Copy constructor called" << std::endl;
}

Form& Form::operator= (const Form& form)
{
    this->_signed = form._signed;
    return *this;
}

const std::string Form::getName() const
{
    return (this->_name);
}

int Form::getSignGrade() const
{
    return (this->_signGrade);
}

int Form::getExecGrade() const
{
    return (this->_execGrade);
}

void Form::beSigned(Bureaucrat bc)
{
    if (bc.getGrade() <= this->_signGrade)
        this->_signed = true;
    else
        throw (Form::GradeTooLowException());
}

int Form::isSigned()
{
    if (this->_signed)
        return 1;
    return 0;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade can't be less than 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade can't be more than 150");
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
    os << form.getName() << ", form sign grade " << form.getSignGrade() << " and execute grade " << form.getExecGrade() << std::endl;
    return os;
}