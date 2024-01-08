/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:10:16 by tgayet            #+#    #+#             */
/*   Updated: 2024/01/08 15:32:24 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact {	
	public:
		void		Contact::setFirstname( std::string fname );
		void		Contact::setLastname( std::string lname );
		void		Contact::setNickname( std::string nname );
		void		Contact::setPhoneNumber( std::string number );
		void		Contact::setDarkSecret( std::string secret );
		std::string	Contact::getFirstname( void );
		std::string	Contact::getLastname( void );
		std::string	Contact::getNickname( void );
		std::string	Contact::getPhoneNumber( void );
		std::string	Contact::getDarkSecret( void );
	
	private:
		std::string firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secrets;
};

#endif