#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat("Blue", 100);
        Bureaucrat("Green", 0);
        Bureaucrat("Red", 160);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}