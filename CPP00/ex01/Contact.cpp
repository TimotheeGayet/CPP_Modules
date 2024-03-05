/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:30:16 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 15:10:18 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact() {
	firstname = "";
	lastname = "";
	nickname = "";
	phone_number = "";
	darkest_secrets = "";
}

Contact::Contact(const Contact& other) {
	firstname = other.firstname;
	lastname = other.lastname;
	nickname = other.nickname;
	phone_number = other.phone_number;
	darkest_secrets = other.darkest_secrets;
}

Contact& Contact::operator=(const Contact& other) {
	if (this != &other) {
		firstname = other.firstname;
		lastname = other.lastname;
		nickname = other.nickname;
		phone_number = other.phone_number;
		darkest_secrets = other.darkest_secrets;
	}
	return *this;
}

Contact::~Contact() {}

int checkAlpha(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isalpha(str[i])) {
			std::cout << "Error\n Entry must be alphabetical characters only" << std::endl;
			return 1;
		}
	}
	return 0;
}

int checkNumber(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			std::cout << "Error\n Entry must be a number" << std::endl;
			return 1;
		}
	}
	return 0;
}

int Contact::initContact( void ) {
	while (firstname.empty() || checkAlpha(firstname)) {
		std::cout << "First name : ";
		std::getline(std::cin, firstname);
		if (std::cin.eof()) {
			std::cout << "Error: EOF" << std::endl;
			std::cin.clear();
			return 1;
		}
		if (firstname.empty())
			std::cout << "Error\n Entry must not be NULL" << std::endl;
	}
	while (lastname.empty() || checkAlpha(lastname)) {
		std::cout << "Last name : ";
		std::getline(std::cin, lastname);
		if (std::cin.eof()) {
			std::cout << "Error: EOF" << std::endl;
			std::cin.clear();
			return 1;
		}
		if (lastname.empty())
			std::cout << "Error\n Entry must not be NULL" << std::endl;
	}
	while (nickname.empty() || checkAlpha(nickname)) {
		std::cout << "Nickname : ";
		std::getline(std::cin, nickname);
		if (std::cin.eof()) {
			std::cout << "Error: EOF" << std::endl;
			std::cin.clear();
			return 1;
		}
		if (nickname.empty())
			std::cout << "Error\n Entry must not be NULL" << std::endl;
	}
	while (phone_number.empty() || checkNumber(phone_number)) {
		std::cout << "Phone number : ";
		std::getline(std::cin, phone_number);
		if (std::cin.eof()) {
			std::cout << "Error: EOF" << std::endl;
			std::cin.clear();
			return 1;
		}
		if (phone_number.empty())
			std::cout << "Error\n Entry must not be NULL" << std::endl;
	}
	while (darkest_secrets.empty() || checkAlpha(darkest_secrets)) {
		std::cout << "Darkest secret : ";
		std::getline(std::cin, darkest_secrets);
		if (std::cin.eof()) {
			std::cout << "Error: EOF" << std::endl;
			std::cin.clear();
			return 1;
		}
		if (darkest_secrets.empty())
			std::cout << "Error\n Entry must not be NULL" << std::endl;
	}
	
	return 0;
}

void Contact::emptyContact( void ) {
	firstname = "";
	lastname = "";
	nickname = "";
	phone_number = "";
	darkest_secrets = "";
}

std::string	Contact::getFirstname( void ){
	return this->firstname;
};

std::string	Contact::getLastname( void ){
	return this->lastname;
};

std::string	Contact::getNickname( void ){
	return this->nickname;
};

std::string	Contact::getPhoneNumber( void ){
	return this->phone_number;
};

std::string	Contact::getDarkSecret( void ){
	return this->darkest_secrets;
};
