#include "Weapon.hpp"

Weapon::Weapon( std::string str ) : type(str) {
    return;
}

Weapon::~Weapon( void ) {
    return;
}

const std::string& Weapon::getType( void ) {
    return type;
}

void Weapon::setType( std::string str ) {
    type = str;
}