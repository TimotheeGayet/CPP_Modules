#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class Pmergeme {
    private:
        Pmergeme();
        Pmergeme(const Pmergeme& other);
        Pmergeme& operator=(const Pmergeme& other);

    public:
        Pmergeme(int argc, char** argv);
        ~Pmergeme();
};

#endif