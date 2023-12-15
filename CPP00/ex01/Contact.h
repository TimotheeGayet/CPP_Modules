/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgayet <tgayet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:09:42 by tgayet            #+#    #+#             */
/*   Updated: 2023/12/13 18:09:42 by tgayet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

class Contact {
	public:
		void	init_contact();

	private:
		char	*firstname;
		char	*lastname;
		char	*nickname;
		char	*phone_number;
		char	*darkest_secrets;
};

#endif