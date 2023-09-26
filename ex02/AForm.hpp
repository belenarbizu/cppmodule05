#ifndef AFORM_HPP
#define AFORM_HPP

class AForm;

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
private:
    std::string const _name;
    bool _signed;
    int const _signGrade;
    int const _execGrade;
public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    virtual ~AForm();
    AForm(const AForm& form);
    AForm& operator= (const AForm& form);

    const std::string getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getSigned() const;

    void beSigned(const Bureaucrat & bc);
    int isSigned() const;
    void canBeExecutable(const Bureaucrat & bc) const;

    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class IsNotSignedException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, AForm& form);

#endif