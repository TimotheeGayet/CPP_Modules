/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:47:26 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 11:24:50 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

class Zombie
{
private:
    std::string name;

public:
    Zombie( std::string str);
    ~Zombie() {};

    void    Zombie::announce( void );
};

#endif