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

    void beSigned(Bureaucrat bc);
    int isSigned();

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
};

std::ostream& operator<<(std::ostream& os, AForm& form);

#endif