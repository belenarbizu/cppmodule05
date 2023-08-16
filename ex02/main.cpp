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
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat("Red", 160);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form* Green = new Form("Green", 100, 10);
        std::cout << Green->getName() << std::endl;
        std::cout << Green->getSignGrade() << std::endl;
        std::cout << Green->getExecGrade() << std::endl;
        Bureaucrat* Yellow = new Bureaucrat("Yellow", 30);
        std::cout << Green->isSigned() << std::endl;
        Yellow->signForm(Green);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
