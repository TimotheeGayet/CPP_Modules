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

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "./Contact.hpp"

class PhoneBook {
public:
	PhoneBook();								
	PhoneBook(const PhoneBook& other);				
	PhoneBook& operator=(const PhoneBook& other);		
	~PhoneBook();											

	int		init_contact();
	int		search();
	void	exit();

private:
	Contact contact_list[8];
	bool boolean_list[8];
};

#endif