#include "Weapon.hpp"

Weapon::Weapon(std::string str) {
    if (str.empty())
        type = "bare hands";
    else
        type = str;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string &str) {
    if (str.empty())
        type = "bare hands";
    else
        type = str;
}