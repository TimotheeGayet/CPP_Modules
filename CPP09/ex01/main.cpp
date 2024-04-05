#include "RPN.hpp"

int main(int argc, char **argv) {
    try
    {
        RPN rpn;
        rpn.run(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}