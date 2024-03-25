#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main(){
    uintptr_t raw = 0;
    Data *data = new Data;

    std::cout << "Data: " << data << std::endl;
    std::cout << "Raw: " << raw << std::endl;
    raw = Serializer::serialize(data);
    std::cout << "Data: " << data << std::endl;
    std::cout << "Raw: " << raw << std::endl;
    data = Serializer::deserialize(raw);
    std::cout << "Data: " << data << std::endl;
    std::cout << "Raw: " << raw << std::endl;
    
    delete data;
    return 0;
}