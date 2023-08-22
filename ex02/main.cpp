#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        AForm Prueba; 
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
