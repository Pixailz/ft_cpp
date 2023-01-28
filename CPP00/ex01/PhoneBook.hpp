/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:41:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 14:00:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	entry[8];
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		// OTHERS
		void	main_loop(void);
		void	add_entry(void);
};
