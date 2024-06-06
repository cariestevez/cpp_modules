#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Seed random number generator for the executer of the robotomyrequestform
	std::srand(std::time(0));

    try
    { 
        Bureaucrat AnonymousLou;
        std::cout << AnonymousLou << std::endl;

        Bureaucrat Max("Musterman", 1);
        std::cout << Max << std::endl;

        ShrubberyCreationForm treeForm("Home");
        std::cout << treeForm << std::endl;

        RobotomyRequestForm roboForm("Mr. RoBoTo");
        std::cout << roboForm << std::endl;

        RobotomyRequestForm roboForm2("RBT3342");
        std::cout << roboForm2 << std::endl;

        PresidentialPardonForm presiForm("Public Enemy");
        std::cout << presiForm << std::endl;

        std::cout << std::endl;

        AnonymousLou.signForm(treeForm);
        AnonymousLou.signForm(roboForm);
        Max.signForm(presiForm);

        AnonymousLou.executeForm(treeForm);
        //AnonymousLou.executeForm(roboForm);//will throw exception bc grade too low
       	Max.executeForm(roboForm);
        //Max.executeForm(roboForm2);// will throw exception bc not signed
        Max.executeForm(presiForm);
        
        std::cout << std::endl;

    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }

    std::cout << std::endl;

	// MORE TESTS
	// AForm*		form;
	// form = new ShrubberyCreationForm("another home");
    // try
	// {
	// 	Bureaucrat	first("Xi", 1);

	// 	std::cout << first << std::endl;
	// 	std::cout << *form << std::endl;
	// 	first.signForm(*form);
	// 	std::cout << *form << std::endl;
	// 	first.executeForm(*form);
	// }
	// catch ( std::exception& e)
	// {
	// 	std::cerr << "Exception found: " << e.what() << std::endl;

	// }
	// delete form;
	// form = new RobotomyRequestForm("Marvin");
	// try
	// {
	// 	Bureaucrat	first("Xi", 1);

	// 	std::cout << first << std::endl;
	// 	std::cout << *form << std::endl;
	// 	first.signForm(*form);
	// 	std::cout << *form << std::endl;
	// 	first.executeForm(*form);
	// 	first.executeForm(*form);
	// 	first.executeForm(*form);
	// 	first.executeForm(*form);
	// 	first.executeForm(*form);
	// 	first.executeForm(*form);
	// 	first.executeForm(*form);
	// 	first.executeForm(*form);
	// }
	// catch ( std::exception& e)
	// {
	// 	std::cerr << "Exception found: " << e.what() << std::endl;
	// }
	// delete form;
	// form = new PresidentialPardonForm("Arthur");
	// try
	// {
	// 	Bureaucrat	first("Xi", 24);

	// 	std::cout << first << std::endl;
	// 	std::cout << *form << std::endl;
	// 	first.signForm(*form);
	// 	std::cout << *form << std::endl;
	// 	first.executeForm(*form);
	// }
	// catch ( std::exception& e)
	// {
	// 	std::cerr << "Exception found: " << e.what() << std::endl;
	// }
	// delete form;

	return 0;
}
