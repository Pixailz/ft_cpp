/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:18:07 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 08:10:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->index = 0;
	this->first_name.clear();
	this->last_name.clear();
	this->nick_name.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
	// std::cout << "Contact class created\n";
}

Contact::~Contact(void) { }
// {
// 	std::cout << "Contact class destructed\n";
// }

void	Contact::set_index(int index)
{
	this->index = index;
}

void	Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nick_name(std::string nick_name)
{
	this->nick_name = nick_name;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string	Contact::get_nick_name(void)
{
	return (this->nick_name);
}

std::string	Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}

std::string	Contact::get_formated(std::string content, int length)
{
	int	content_size = content.size();

	if (content_size < length)
		return (std::string(length - content_size, ' ') + content);
	else
		return (std::string(content, 0, length - 1) + '.');
}

void	Contact::print_contact(void)
{
	std::cout << this->index << std::endl
			  << this->first_name << std::endl
			  << this->last_name << std::endl
			  << this->nick_name << std::endl
			  << this->phone_number << std::endl
			  << this->darkest_secret << std::endl;
}

void	Contact::print_contact_formated(int length)
{
	std::cout << std::setfill(' ') << std::setw(length) << this->index << '|'
			  << get_formated(this->first_name, length) << '|'
			  << get_formated(this->last_name, length) << '|'
			  << get_formated(this->nick_name, length) << '|'
			  << get_formated(this->phone_number, length) << std::endl;
}
