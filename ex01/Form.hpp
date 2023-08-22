#ifndef FORM_HPP
#define FORM_HPP

class Form;

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
private:
    std::string const _name;
    bool _signed;
    int const _signGrade;
    int const _execGrade;
public:
    Form();
    Form(std::string name, int signGrade, int execGrade);
    ~Form();
    Form(const Form& form);
    Form& operator= (const Form& form);

    const std::string getName() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(Bureaucrat &bc);
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

std::ostream& operator<<(std::ostream& os, Form& form);

#endif