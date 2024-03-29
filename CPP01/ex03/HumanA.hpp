#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA( std::string str, Weapon &weapon );
        ~HumanA( void );

        void attack( void );
    
    private:
        std::string _name;
        Weapon &_weapon;
};

#endif