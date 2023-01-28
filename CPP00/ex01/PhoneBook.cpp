/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:40:54 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 14:37:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook class created\n";
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook class destructed\n";
}

void	PhoneBook::print_all_entry(void)
{
	
}

void	PhoneBook::add_entry(void)
{
	
}

void	PhoneBook::main_loop(void)
{
	std::string	user_input;
	int			looping;

	looping = 1;
	while (looping)
	{
		std::cout << "> ";
		std::cin >> user_input;
		if (user_input == "EXIT")
			looping = 0;
		else
			std::cout << "NOT A VALID COMMAND\n";
	}
}
