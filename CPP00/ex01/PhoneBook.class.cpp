/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:33 by tgayet            #+#    #+#             */
/*   Updated: 2024/01/08 17:56:57 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

Contact	PhoneBook::init_contact() {
	Contact new;

	while (firstname) {
		std::cout << "First name :"; std::cin >> new.firstname;
		if (!new.firstname) {
			std::cout << "Error\n Entry must not be NULL";
            return NULL;
        }
	}
	while (!new.lastname) {
		std::cout << "Last name :";std::cin >> new.lastname;
		if (!new.lastname)
			std::cout << "Error\n Entry must not be NULL";
	}
	while (!new.nickname) {
		std::cout << "Nickname :";std::cin >> new.nickname;
		if (!new.nickname)
			std::cout << "Error\n Entry must not be NULL";
	}
	while (!new.phone_number) {
		std::cout << "Phone number :";std::cin >> new.phone_number;
		if (!new.phone_number)
			std::cout << "Error\n Entry must not be NULL";
	}
	while (!new.darkest_secret) {
		std::cout << "Darkest Secret :";std::cin >> new.darkest_secret;
		if (!new.darkest_secret)
			std::cout << "Error\n Entry must not be NULL";
	}
}

int		PhoneBook::phonebook_len() {
	int i = 0;
	Contact *temp;

	temp = this.contact_list;
	while (temp) {
		temp = temp.next;
		i ++;
	}
	return i;
}

void	print_table(int width, std::str s) {
    if (s.length() > width)
		std::cout << "|" << std::setw(width) << s.resize(width - 1) << "." << std::endl;
	else
		std::cout << "|" << std::setw(width) << s << std::endl;
}

void	PhoneBook::search() {
	Contact *temp;

	std::cout << "|     index|first name| last name|  nickname|";
	temp = this.contact_list;
	while (temp) {
		print_table();
		temp = temp.next;
	}
}

void	PhoneBook::exit() {

}
