#include "RPN.hpp"

int main(int argc, char **argv)
{
    int *jacobsthalSequence = generateJacobsthalSequence(n);

    std::vector<int> insertionSequence;

    insertionSequence[0] = jacobsthalSequence[3];
    insertionSequence[1] = jacobsthalSequence[3] - 1;

    int i = 1, j = 3;

    for ( ; ++i < n;)
    {
        int last = j;
        int num = jacobsthalSequence[last - 1];
        j++;
        while (num > jacobsthalSequence[last])
        {
            insertionSequence[i] = num;
            i++;
            num--;
        }

    }
}
    // if (argc != 2)
    // {
    //     std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
    //     return 1;
    // }
    
    // RPN rpnCalculator(argv[1]);
    // rpnCalculator.calculateExpression();

    // return 0;
}
