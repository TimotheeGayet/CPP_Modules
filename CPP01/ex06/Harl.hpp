#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
    public :
        Harl();
        ~Harl();

        void complain( std::string level );
    
    private :
        void debug( void );
        void error( void );
        void info( void );
        void warning( void );
};

#endif