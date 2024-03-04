/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:02:45 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 11:19:00 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Zombie.hpp"

Zombie::Zombie( void ) {
	name = "Zombie";
}

Zombie::Zombie( std::string str ) {
	name = str;
}

Zombie::~Zombie( void ) {
	std::cout << name << " is dead." << std::endl;
}

void    Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::changeName( std::string str ) {
	name = str;
}