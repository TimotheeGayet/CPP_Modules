/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:05:20 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 15:12:34 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	boolean_list[0] = false;
	return ;
}


PhoneBook::PhoneBook(const PhoneBook& other) {
    for (int i = 0; i < 8; ++i) {
        contact_list[i] = other.contact_list[i];
    }
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            contact_list[i] = other.contact_list[i];
        }
    }
    return *this;
}

PhoneBook::~PhoneBook() {}

int	PhoneBook::init_contact() {
	int	i = 0;

	while (i < 8 && boolean_list[i])
		i++;
	if (i < 8) {
		if (contact_list[i].initContact()){
			return 1;
		}
		boolean_list[i] = true;
	}
	else {
		for (int j=1; j<8; j++) {
			contact_list[j - 1] = contact_list[j];
		}
		std::cerr << "\nContact list is full, oldest contact has been removed" << std::endl;
		contact_list[7].emptyContact();
		if (contact_list[7].initContact() == 1){
			return 1;
		}
	}
	
	return 0;
}

void	tabOverflow(std::string str) {
	int	space_nbr = 10 - str.length();

	if (str.length() <= 10) {
		while (space_nbr){
			std::cout << " ";
			space_nbr--;
		}
		for (long j=0; j < (long)str.length(); j++) {
			std::cout << str[j];
		}
	} else if (str.length() > 10) {
		for (int j=0; j < 9; j++) {
			std::cout << str[j];
		}
		std::cout << '.';
	}
}

int	PhoneBook::search() {
	std::string input = "";

	if (!boolean_list[0]) {
		std::cout << "Aucun contact enregistré\n" << std::endl;
		return 0;
	}

	std::cout << "\n|     index|first name| last name|  nickname|\n";
	for (int i=0; i<8; i++) {
		if (boolean_list[i]) {			
			std::cout << '|' << "         " << i+1 << '|';
			tabOverflow(contact_list[i].getFirstname());
			std::cout << '|';
			tabOverflow(contact_list[i].getLastname());
			std::cout << '|';
			tabOverflow(contact_list[i].getNickname());
			std::cout << '|' << std::endl;
		}
	}

	std::cout << "\nVeuillez entrer un id : "; std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "Error: EOF" << std::endl;
		std::cin.clear();
		return 1;
	}
	else if (input.length() == 1 && input != "0" && input != "9" && isdigit(input[0]) && boolean_list[(int)input[0] - 49]) {
		std::cout << "Firstname : " << contact_list[input[0] - 49].getFirstname() << "\n";
		std::cout << "Lastname : " << contact_list[input[0] - 49].getLastname() << "\n";
		std::cout << "Nickname : " << contact_list[input[0] - 49].getNickname() << "\n";
		std::cout << "Phone number : " << contact_list[input[0] - 49].getPhoneNumber() << "\n";
		std::cout << "Dark Secret : " << contact_list[input[0] - 49].getDarkSecret() << "\n\n";
	} else {
		std::cout << "Id invalide\n" << std::endl;
	}
	
	return 0;
}

void	PhoneBook::exit() {
	return ;
}
