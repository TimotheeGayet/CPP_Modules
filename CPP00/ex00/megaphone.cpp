/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:07:17 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 14:26:47 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	
	int	i = 0;
	int	j = -1;

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}

	while (argv[++i]) {
		j = -1;

		while (argv[i][++j]){
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
		if (argv[i + 1])
			std::cout << ' ';
	}
	std::cout << std::endl;

	return 0;
}
