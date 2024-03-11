#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    public:
        Weapon( std::string str );
        ~Weapon( void );

        const std::string& getType( void ) const;
        void setType( const std::string &str );

    private:
        std::string type;
};

#endif