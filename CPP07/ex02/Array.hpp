#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private :
        T *_array;
        unsigned int _size;

    public :
        Array() { _array = new T[0]; _size = 0; };
        Array(unsigned int n) { _array = new T[n]; _size = n; };
        Array(Array const &src) { *this = src; };
        Array &operator=(Array const &src) {
            if (this != &src) {
                delete
                _array = new T[src.size()];
                for (unsigned int i = 0; i < src.size(); i++) {
                    _array[i] = src[i];
                }
                _size = src.size();
            }
            return *this;
        };
        ~Array() { delete[] _array; };

        T &operator[](unsigned int i) {
            if (i >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _array[i];
        };

        unsigned int size() const { return _size; };
};

#endif