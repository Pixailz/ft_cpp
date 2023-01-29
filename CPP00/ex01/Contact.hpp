/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:18:07 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 07:11:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#ifndef CONTACT_CLASS
# define CONTACT_CLASS

class Contact
{
	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

		std::string get_formated(std::string content, int length);

	public:
		// CONSTRUCTOR
		Contact(void);

		// DESTRUCTOR
		~Contact(void);

		// SETTERS
		void		set_index(int index);
		void		set_first_name(std::string first_name);
		void		set_last_name(std::string last_name);
		void		set_nick_name(std::string nick_name);
		void		set_phone_number(std::string phone_number);
		void		set_darkest_secret(std::string darkest_secret);

		// GETTERS
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nick_name(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);

		// OTHERS
		void		print_contact(void);
		void		print_contact_formated(int length);
};

# endif // CONTACT_CLASS
