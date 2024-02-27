/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:10:16 by tgayet            #+#    #+#             */
/*   Updated: 2024/02/27 15:10:28 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact {	
	public:
	    Contact();  							// Constructeur par défaut
		Contact(const Contact& other);  			// Constructeur de copie
		Contact& operator=(const Contact& other);		// Opérateur d'assignation
		~Contact();  										// Destructeur
	
		int		initContact( void );
		void		emptyContact( void );
		std::string	getFirstname( void );
		std::string	getLastname( void );
		std::string	getNickname( void );
		std::string	getPhoneNumber( void );
		std::string	getDarkSecret( void );
	
	private:
		std::string firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secrets;
};

#endif