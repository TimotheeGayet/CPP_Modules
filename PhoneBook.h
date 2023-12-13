/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:09:36 by tgayet            #+#    #+#             */
/*   Updated: 2023/12/13 18:09:36 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {
	public:
		void    add();
		void	search();
		void	exit();

	private:
		char contact[8] = NULL;
};

#endif