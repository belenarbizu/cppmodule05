#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat;

#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat {
private:
    std::string const _name;
    int _grade;
    Bureaucrat(const Bureaucrat& bc);
    Bureaucrat& operator= (const Bureaucrat& bc);
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    
    const std::string getName() const;
    int getGrade() const;

    void addGrade();
    void subtractGrade();

    void signForm(AForm& form);
    void executeForm(AForm const & form);

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