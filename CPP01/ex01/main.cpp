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

    int N = 20;

    Zombie* horde = zombieHorde(N, "zombie");
    if (!horde)
        return 1;

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;

    return 0;
}