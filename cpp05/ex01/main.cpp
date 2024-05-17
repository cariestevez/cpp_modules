#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat AnonymousLou;

    std::cout << AnonymousLou << std::endl;

    try
    {
        AnonymousLou.decrementGrade();
        std::cout << AnonymousLou << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;//"what" prints the specific error defined for the thrown exception
    }

    try
    {
        Bureaucrat Rosa("Doing Good", 100);
    
        std::cout << Rosa << std::endl;
        
        Rosa.incrementGrade();
        std::cout << Rosa << std::endl;

        Rosa.incrementGrade();
        std::cout << Rosa << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;//"what" prints the specific error defined for the thrown exception
    }

    try
    {
        Bureaucrat Olivia("Too Intelligent", 0);
    
        std::cout << Olivia << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;//"what" prints the specific error defined for the thrown exception
        // std::cout << "Object not created due to exception." << std::endl;
    }

    try
    {
        Bureaucrat Antonio("Improving Too Much", 2);
        std::cout << Antonio << std::endl;

        Antonio.incrementGrade();
        std::cout << Antonio << std::endl;

        Antonio.incrementGrade(); // should throw an exception
        std::cout << Antonio << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Bobby("Doing Bad", 149);
        std::cout << Bobby << std::endl;

        Bobby.decrementGrade();
        std::cout << Bobby << std::endl;

        Bobby.decrementGrade(); // should throw an exception
        std::cout << Bobby << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalid("Too Bad", 151); // should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
        // std::cout << "Object not created due to exception." << std::endl;
    }
    
    return 0;
}
