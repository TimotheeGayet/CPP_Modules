/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:07:17 by tgayet            #+#    #+#             */
/*   Updated: 2023/12/11 20:02:41 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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
			if (argv[i][j] > 96 && argv[i][j] < 123)
				std::cout << (char)(argv[i][j] - 32);
			else
				std::cout << argv[i][j];
		}
	}
	std::cout << '\n';

	return 0;
}
