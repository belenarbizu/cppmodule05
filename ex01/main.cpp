#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat* Blue = new Bureaucrat("Blue", 100);
        Blue->addGrade();
        std::cout << Blue->getGrade() << std::endl;
        std::cout << Blue->getName() << std::endl;
        Blue->subtractGrade();
        std::cout << Blue->getGrade() << std::endl;
        delete Blue;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    try
    {
        Bureaucrat("Red", 160);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    try
    {
        Form Green("Green", 100, 10);
        std::cout << Green.getName() << std::endl;
        std::cout << Green.getSignGrade() << std::endl;
        std::cout << Green.getExecGrade() << std::endl;
        Bureaucrat Yellow("Yellow", 30);
        std::cout << Green.isSigned() << std::endl;
        Yellow.signForm(Green);
        std::cout << Green.isSigned() << std::endl;
        std::cout << Green;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    try
    {
        Form("Red", 160, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------" << std::endl;
    try
    {
        Form("Red", 1, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------" << std::endl;
    try
    {
        Form Black("Black", 120, 28);
        Form CopyBlack(Black);
        std::cout << CopyBlack.getName() << std::endl;
        std::cout << CopyBlack.getSignGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
