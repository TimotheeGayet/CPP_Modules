/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:58:36 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 11:23:20 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int    main() {
    Zombie* z = newZombie( "zombie" );
    Zombie z2( "zombie2" );

    z->announce();
    z2.announce();  

    randomChump( "chump" );

    delete z;

    return 0;
}