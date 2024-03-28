#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <algorithm>

class Span
{
    private:
        Span();

        unsigned int    _size;
        std::set<int>   _table;

    public:

        // Constructor

        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        // Methods

        void addNumber(int nbr);
        int shortestSpan();
        int longestSpan();

        // Template Methods

        template <typename T>
        void addSet(typename T::iterator a, typename T::iterator b){
            std::sort(a, b);
            std::merge(this->_table.begin(), this->_table.end(), a, b, this->_table);
        }

        // Errors

        class SpanFullError : public std::exception {
            public :
                virtual const char *what() const throw();
        };
        class SpanEmpty : public std::exception {
            public :
                virtual const char *what() const throw();
        };
        class SpanNotEnoughElements : public std::exception {
            public :
                virtual const char *what() const throw();
        };
};

#endif