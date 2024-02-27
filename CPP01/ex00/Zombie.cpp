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

Zombie::Zombie( std::string str ) {
	name = "zombie";
	if (str != "")
		name = str;
}

void    Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...";
}