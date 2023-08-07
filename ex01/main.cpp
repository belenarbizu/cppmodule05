#include "Bureaucrat.hpp"

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
        Bureaucrat("Red", 0);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
