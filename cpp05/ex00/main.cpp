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
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
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
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Olivia("Too Intelligent", 0);
    
        std::cout << Olivia << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Antonio("Improving Too Much", 2);
        std::cout << Antonio << std::endl;

        Antonio.incrementGrade();
        std::cout << Antonio << std::endl;

        Antonio.incrementGrade();
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

        Bobby.decrementGrade();
        std::cout << Bobby << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalid("Too Bad", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[1;31mException caught: \e[0m" << e.what() << std::endl;
    }
    
    return 0;
}

// /////////////////////////////////// VERSION 1 ///////////////////////////////////
// void test1()
// {
//     try
//     {
//        if(/*there's an error*/)//actual test code
//        {
//             throw std::exception();//creates the exception
//        }
//        else
//        {
//             /*do whathever*/
//        }
//     }
//     catch(const std::exception e)//if there's an exception, it catches it and executes the code inside of here
//     {
//        //code for handling error like output error msg or deallocate memory if previously alloc in try block
//     }   
// }

// /////////////////////////////////// VERSION 2 ///////////////////////////////////

// void testPart1()
// {
//     //do some stuff
//     if (/*there's an error*/)
//     {
//         throw std::exception();
//     }
//     else
//     {
//         //do whatever
//     }
// }

// void testPart2()
// {
//     try
//     {
//         testPart1();//if this func threw an exception, it's fetched by this function
//     }
//     catch(const std::exception& e)//catches the exception by reference
//     {
//        //code for handling error like output error msg or deallocate memory if previously alloc in try block
//     }
// }

// /////////////////////////////////// VERSION 3 ///////////////////////////////////

// void test1()
// {
//     class WHATEVERException : public std::exception//class can now be manipulated as an exception
//     {
//         public:
//             virtual const char *what() const throw()//may throw an exception that is specified in the brakets
//             {
//                 return (/*specific error msg for WHATEVER*/);
//             }
//     };

//     try
//     {
//         testPart2();//might throw an WAHTEVERException or any other type
//     }
//     catch(WHATEVERException &e)//specific catch: if whatever is returnd, it's handled in this block
//     {
//         //handle this specific exception
//     }
//     catch(const std::exception &e)//generic catch: if it's another type of exception, it'll be handled here
//     {
//         //handle the other exceptions
//     }
    
// }

//use the exceptions exceptionally! they use many resources
//only for exceptional errors that might occur, not for normal error returning of funcs
//for ex: 'new' returns an BAD ALLOC EXCEPTION if there's not enough memory available
//it's a good practice to handle exceptions at the highest level possible
//where you have enough context to deal with them appropriately.
//This often means that exceptions should be caught in the main function or in other high-level functions
//that can make meaningful decisions about how to recover from an error or how to log it.
// - Centralized Error Handling: makes it easier to manage and maintain the code.
//You can decide how to log errors, clean up resources, or perform other actions based on the type of error.
// - Separation of Concerns: It separates the error-handling logic from the core functionality of your classes.
//Your class methods should focus on their main responsibilities, and exception handling can be dealt with separately.
// - Flexibility: Handling exceptions at a higher level provides more flexibility in deciding what to do with different types of exceptions.
//For example, you might want to retry an operation, provide user feedback, or terminate the program.
//Exception Thrown: For example, if checkGrade is called with 151, it throws GradeTooLowException
//Stack Unwinding: The exception stops the constructor execution, and the destructor is called for any fully constructed base or member objects
//(though in this case, name is a simple type and doesn't require explicit destruction).
//Catch Block Search: The runtime looks up the call stack for a matching catch block.
//Main Catch Block: If the constructor was called in a try block in main, the control is transferred to the corresponding catch block in main,
//and the exception is handled by printing an error message.
