/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:11:30 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 11:21:56 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void	randomChump( std::string name ) {
	Zombie z = Zombie( name );

	z.announce();
}