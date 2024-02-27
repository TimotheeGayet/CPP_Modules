/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:35:25 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 14:48:21 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>
# include "./Contact.class.hpp"

class PhoneBook {
public:
	PhoneBook();								// Constructeur par défaut
	PhoneBook(const PhoneBook& other);				// Constructeur de copie
	PhoneBook& operator=(const PhoneBook& other);		// Opérateur d'assignation
	~PhoneBook();											// Destructeur

	int		init_contact();
	int		search();
	void	exit();

private:
	Contact contact_list[8];
	bool boolean_list[8];
};

#endif