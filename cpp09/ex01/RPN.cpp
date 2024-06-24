#include "RPN.hpp"

RPN::RPN(const std::string &userInput)
{
    processInput(userInput);
    std::cout << "\e[0;103mRPN::\e[0m Default constructor called" << std::endl;
}

RPN::RPN(const RPN &source) : op(source.op)
{
    std::cout << "\e[0;103mRPN::\e[0m Copy constructor called" << std::endl;
}

RPN &RPN::operator=(const RPN &source)
{
    if (this != &source)
    {
        op = source.op;
    }
    std::cout << "\e[0;103mRPN::\e[0m Assignment operator used" << std::endl;
	return (*this);
}

RPN::~RPN()
{
    std::cout << "\e[0;103mRPN::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void RPN::processInput(const std::string &input)
{
    if (!isValidExpression(input))
        return ;
    
    for (size_t i = 0; i < input.size(); i++)
    {
        expression[i] = input[i];
    }
}

bool RPN::isValidExpression(const std::string &input) const
{
    if (input.empty())
    {
        std::cout << "Error: input string is empty" << std::endl;
        return false;
    }

    std::string charsToFind = "0123456789+-/*";
    size_t pos = input.find_first_not_of(charsToFind);

    if (pos != std::string::npos)
    {
        std::cout << "Error: invalid character in the expression" << std::endl;
        return false;
    }

    return true;
}

int RPN::applyOperator(const int &a, const int &b, const std::string &operatorToken)
{
    if (operatorToken == "+")
    {
        std::cout << "Operation: " << a + b << std::endl;
        return a + b;
    }
    if (operatorToken == "-")
    {
        std::cout << "Operation: " << a - b << std::endl;
        return a - b;
    }
    if (operatorToken == "*")
    {
        std::cout << "Operation: " << a * b << std::endl;
        return a * b;
    }
    if (operatorToken == "/")
    {
        std::cout << "Operation: " << a / b << std::endl;
        return a / b;
    }
    throw std::invalid_argument("Exception ocurred: Invalid operator");
}

void RPN::calculateExpression(void)
{
    size_t result = 0;
    std::string operatorToken;
    bool error = false;
    int count = 0;

    //do operations
    std::stack<int> op;
    for (size_t i = 0; i < expression.size() && error == false; i++)
    {
        if (isdigit(expression[i]))
        {
            std::cout << "Operation: " << a + b << std::endl;

            count++;
            if (count > 2)
            {
                error = true;
                continue;
            }
            op.push(expression[i]);
        }
        else if (!op.empty())
        {
            operatorToken = expression[i];
            int a = op.top();
            op.pop();
            if (!op.empty())
            {
                int b = op.top();
                op.pop();
                try
                {
                    op.push(applyOperator(a, b, operatorToken));
                }
                catch(const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                    error = true;
                }
                
            }
            else
                error = true;
        }
        else
                error = true;

    }

    if (error == true)
    {
        std::cout << "Error: invalid RPN expression" << std::endl;
        return ;
    }

    std::string resultStr;
    std::stringstream iss;
    iss << result;
    resultStr = iss.str();

    std::cout << resultStr << std::endl;
}