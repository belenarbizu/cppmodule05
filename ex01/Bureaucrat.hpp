#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat;

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat {
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& bc);
    Bureaucrat& operator= (const Bureaucrat& bc);
    
    const std::string getName();
    int getGrade();

    void addGrade();
    void subtractGrade();

    void signForm(Form &form);

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

std::ostream& operator<<(std::ostream& os, Bureaucrat& bc);

#endif