/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:18:07 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 14:32:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact(void) {}
// {
// 	std::cout << "Contact class created!\n";
// }

Contact::~Contact(void) {}
// {
// 	std::cout << "Contact class destructed!\n";
// }

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nick_name(std::string nick_name)
{
	this->_nick_name = nick_name;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string	Contact::get_nick_name(void)
{
	return (this->_nick_name);
}

std::string	Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}

void	Contact::print_contact(void)
{
	std::cout << "First Name: {" << this->_first_name << "}\n";
	std::cout << "Last Name: {" << this->_last_name << "}\n";
	std::cout << "Nick Name: {" << this->_nick_name << "}\n";
	std::cout << "Phone Number: {" << this->_phone_number << "}\n";
	std::cout << "Darkest secret: {" << this->_darkest_secret << "}\n";
}
