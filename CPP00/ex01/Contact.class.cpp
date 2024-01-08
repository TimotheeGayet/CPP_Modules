/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:30:16 by tgayet            #+#    #+#             */
/*   Updated: 2024/01/08 17:57:25 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

void Contact::setFirstname( std::string fname){
	this->firstname = fname;
	return;
};

void Contact::setLastname( std::string lname){
	this->lastname = lname;
	return;
};

void Contact::setNickname( std::string nname){
	this->nickname = nname;
	return;
};

void Contact::setPhoneNumber( std::string number){
	this->phone_number = number;
	return;
};

void Contact::setDarkSecret( std::string secret){
	this->darkest_secrets = secret;
	return;
};

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
