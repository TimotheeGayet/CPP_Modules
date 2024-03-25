#include "Serializer.hpp"
#include <inttypes.h> 
#include "Data.hpp"

Serializer::Serializer(){};
Serializer::Serializer(Serializer const &other){
    *this = other;
};
Serializer &Serializer::operator=(Serializer const &other){
    *this = other;
    return *this;
};
Serializer::~Serializer(){};


uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}