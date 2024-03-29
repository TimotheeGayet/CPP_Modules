#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {
    public:
        HumanB( std::string str);
        ~HumanB( void );

        void setWeapon( Weapon &weapon );
        void attack( void );
    
    private:
        const std::string _name;
        Weapon *_weapon;
};

#endif