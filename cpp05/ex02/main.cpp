#include "Bureaucrat.hpp"

int main()
{
    try
    { 
        Bureaucrat AnonymousLou;
        std::cout << AnonymousLou << std::endl;

        Bureaucrat Max("Musterman", 1);
        std::cout << Max << std::endl;
        
        Form Default;
        std::cout << Default << std::endl;

        Form Anmeldung("Anmeldung", 1, 1);
        std::cout << Anmeldung << std::endl;

        AnonymousLou.signForm(Default);
        Max.signForm(Anmeldung);
        AnonymousLou.signForm(Anmeldung);
        Max.signForm(Default);//doesn't arrive here bc exception was thrown before

    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;//"what" prints the specific error defined for the thrown exception
    }
    
    return 0;
}
