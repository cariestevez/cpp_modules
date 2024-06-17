#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::stack<int> test;
    std::cout << "Testing empty stack behavior:" << std::endl;
    std::cout << "Empty stack size: " << mstack.size() << std::endl;
    std::cout << "Is empty stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;
    //Uncomment the following line to test top() on an empty stack
    // std::cout << "Empty stack top: " << mstack.top() << std::endl;
    //std::cout << "Trying to use top on empty stack: " << test.top() << std::endl;
    //std::cout << "Trying to use top on empty MutantStack: " << mstack.top() << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "MutantStack top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "MutantStack size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    test.push(5);
    test.push(17);
    std::cout << "Stack top: " << test.top() << std::endl;
    test.pop();
    std::cout << "Stack size: " << test.size() << std::endl;
    test.push(3);
    test.push(5);
    test.push(737);
    
    std::cout << std::endl;
    
    mstack.push(0);

    std::cout << "Testing copy constructor and assignment operator:" << std::endl;
    MutantStack<int> copiedStack(mstack);
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Copied stack top: " << copiedStack.top() << std::endl;
    std::cout << "Assigned stack top: " << assignedStack.top() << std::endl;

    std::cout << std::endl;

    std::cout << "Testing iterators:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Testing reverse iterators:" << std::endl;
    MutantStack<int>::reverse_iterator rIter = mstack.rbegin();
    MutantStack<int>::reverse_iterator rIterEnd = mstack.rend();
    while (rIter != rIterEnd)
    {
        std::cout << *rIter << std::endl;
        ++rIter;
    }

    std::cout << std::endl;

    std::cout << "Testing conversion to std::stack:" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "MutantStack: " << std::endl;
    while (!mstack.empty())
    {
        std::cout << mstack.top() << std::endl;
        mstack.pop();
    }
    std::cout << "std::stack: " << std::endl;
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    // std::cout << "\nTesting push and pop operations with chars:" << std::endl;
    // MutantStack<char> charStack;
    // charStack.push('a');
    // charStack.push('b');
    // charStack.push('c');
    // std::cout << "Top after pushes: " << charStack.top() << std::endl;
    // charStack.pop();
    // std::cout << "Top after one pop: " << charStack.top() << std::endl;
    // charStack.push('d');
    // std::cout << "Top after push 'd': " << charStack.top() << std::endl;

    // std::cout << "Testing iterators with strings:" << std::endl;
    // MutantStack<std::string> strStack;
    // strStack.push("hello");
    // strStack.push("world");
    // strStack.push("!");
    // MutantStack<std::string>::iterator iter = strStack.begin();
    // MutantStack<std::string>::iterator iterEnd = strStack.end();
    // while (iter != iterEnd)
    // {
    //     std::cout << *iter << " ";
    //     ++iter;
    // }

    return 0;
}
