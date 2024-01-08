/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:35:25 by tgayet            #+#    #+#             */
/*   Updated: 2024/01/08 16:51:14 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>
# include "./Contact.class.hpp"

class PhoneBook {
	public:
		void	init_contact();
		void	search();
		void	exit();

	private:
		Contact	contact_list[8];
};

#endif