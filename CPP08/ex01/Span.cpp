#include "Span.hpp"
#include <set>

Span::Span(){}

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other){
    if (this != &other){
        _size = other._size;
        _table = other._table;
    }
    return *this;
}

Span::~Span(){
    _table.clear();
}

void Span::addNumber(int nbr){
    if (this->_table.size() >= this->_size)
        throw Span::SpanFullError();

    this->_table.insert(nbr);
}

int Span::shortestSpan() {
    if (this->_table.empty())
        throw Span::SpanEmpty();
    if (this->_table.size() == 1)
        throw Span::SpanNotEnoughElements();

    std::set<int>::iterator it = this->_table.begin();
    int prev = *it;
    int current;
    int shortSpan = *(this->_table.rbegin()) - *(this->_table.begin());

    while (++it != this->_table.end()) {
        current = *it;
        int span = current - prev;
        if (span < shortSpan) {
            shortSpan = span;
        }
        prev = current;
    }
    
    return shortSpan;
}

int Span::longestSpan(){
    if (this->_table.empty())
        throw Span::SpanEmpty();
    if (this->_table.size() == 1)
        throw Span::SpanNotEnoughElements();
    return (*(this->_table.rbegin()) - *(this->_table.begin()));
}

const char *Span::SpanFullError::what() const throw(){
    return "Span is full";
}

const char *Span::SpanEmpty::what() const throw(){
    return "Span is empty";
}

const char *Span::SpanNotEnoughElements::what() const throw(){
    return "Span has only one element";
}