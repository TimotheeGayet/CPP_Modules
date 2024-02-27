/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:10:00 by tgayet            #+#    #+#             */
/*   Updated: 2023/12/13 18:10:00 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Contact.class.hpp"
#include "./PhoneBook.class.hpp"

int main() {
	std::string input = "";
	PhoneBook phonebook;

	std::cout << "Bienvenue,\n";
	while (true) {
		std::cout << "Veuillez executer une des commandes suivantes :\n- ADD\n- SEARCH\n- EXIT\n\nInput: ";
		std::getline(std::cin, input);
		std::cout << "\n";
		if (std::cin.eof()) {
			std::cout << "\nError: EOF encountered." << std::endl;
			break;
		}
		else if (input == "EXIT") {
			break;
		}
		else if (input == "ADD") {
			if (phonebook.init_contact() == 1) {
				return 1;
			}
		}
		else if (input == "SEARCH") {
			if (phonebook.search() == 1) {}
		}
		std::cout << "\n";
	}

	return 0;
}
