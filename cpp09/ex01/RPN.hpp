#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>

class RPN
{
    private:

    public:
        RPN();
        RPN(const RPN &source);
        RPN &operator=(const RPN &source);
        ~RPN();

        void processInput(std::string &input);
        bool isValidExpression(std::string &input);
};

#endif // RPN_HPP
