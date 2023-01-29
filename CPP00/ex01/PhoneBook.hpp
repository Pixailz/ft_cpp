/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:41:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 09:11:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

# include <cstdlib>
/**
 * std::setw()
 * std::setfill()
 */
#include <limits>
/**
 * std::numeric_limits
 */
# define	PHONE_BOOK_SIZE		8

class PhoneBook
{
	private:
		Contact	phone_book[PHONE_BOOK_SIZE];
		size_t	nb_phone_book;

		void		update_index(void);

		void		print_left_padded(std::string str);
		void		print_right_padded(std::string str);
		void		print_all_entry(void);

		void		search_phone_book(void);

		std::string	get_entry(std::string name);
		void		add_phone_book_entry(Contact entry);
		bool		check_add_phone(Contact user_input);
		void		add_phone_book(void);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		// OTHERS
		void		main_loop(void);
};

# endif // PHONEBOOK_CLASS
