#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie( std::string str);
        ~Zombie();

        void    announce( void );
};

void	randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif