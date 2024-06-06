#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"

int main()
{
    std::srand(std::time(0));
    
    try
    { 
        Intern someRandomIntern;
        Form *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        //rrf = someRandomIntern.makeForm("whateverrr", "nono");
        Bureaucrat Max("Musterman", 1);
        std::cout << Max << std::endl;

        if (rrf)
        {
            try
            {
                Max.signForm(*rrf);
                Max.executeForm(*rrf);
                std::cout << std::endl;
            }
            catch(const std::exception &e)
            {
                delete rrf;
                std::cerr << e.what() << '\n';
            }
            delete rrf;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
