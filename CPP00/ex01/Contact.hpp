/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:18:07 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 14:32:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_darkest_secret;
		
	public:
		Contact(void);
		~Contact(void);
		// SETTERS
		void		set_first_name(std::string);
		void		set_last_name(std::string);
		void		set_nick_name(std::string);
		void		set_phone_number(std::string);
		void		set_darkest_secret(std::string);

		// GETTERS
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nick_name(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);

		// OTHERS
		void		print_contact(void);
};
