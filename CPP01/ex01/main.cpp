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

#include "./Zombie.hpp"
#include <iostream>

int    main() {
    int nbr = 0;
    std::string name;

    std::cout << "How many zombies do you want to create ? ";
    std::cin >> nbr;
    std::cout << "What's their name ? ";
    std::cin >> name;

    Zombie* horde = zombieHorde( nbr, name );

    for (int i = 0; i < nbr; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}