/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		PhoneBook.cpp                          | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP00-ex01                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−30T11:33:55+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	nb_phone_book = 0;
	update_index();
	// std::cout << "PhoneBook class created\n";
}

PhoneBook::~PhoneBook(void) { }
// {
// 	std::cout << "PhoneBook class destructed\n";
// }

void	PhoneBook::add_phone_book(void)
{
	Contact	user_input;

	user_input.set_first_name(get_entry("first_name"));
	user_input.set_last_name(get_entry("last_name"));
	user_input.set_nick_name(get_entry("nick_name"));
	user_input.set_phone_number(get_entry("phone_number"));
	user_input.set_darkest_secret(get_entry("darkest_secret"));
	if (check_add_phone(user_input))
		std::cout << "one field is empty" << std::endl;
	else
		add_phone_book_entry(user_input);
}

void	PhoneBook::add_phone_book_entry(Contact entry)
{
	if (nb_phone_book == PHONE_BOOK_SIZE)
	{
		for (int i = PHONE_BOOK_SIZE - 2; i >= 0; i--)
			phone_book[i + 1] = phone_book[i];
		phone_book[0] = entry;
	}
	if (nb_phone_book < PHONE_BOOK_SIZE)
	{
		nb_phone_book++;
		phone_book[nb_phone_book - 1] = entry;
	}
	update_index();
}

void	PhoneBook::update_index(void)
{
	for (int i = 0; i < PHONE_BOOK_SIZE; i++)
		this->phone_book[i].set_index(i + 1);
}

void	PhoneBook::search_phone_book(void)
{
	std::string	line;
	int			converted;
	char		*ptr;

	this->print_all_entry();
	std::cout << "(1-8)> ";
	getline(std::cin, line);
	converted = strtol(line.c_str(), &ptr, 10);
	if (!*ptr && converted > 0 && converted < PHONE_BOOK_SIZE)
		this->phone_book[converted - 1].print_contact();
	else
		std::cout << "wrong index\n";
}

void	PhoneBook::print_all_entry(void)
{
	for (int i = 0; i < PHONE_BOOK_SIZE; i++)
		this->phone_book[i].print_contact_formated(10);
}

void	PhoneBook::print_left_padded(std::string str)
{
	std::cout << std::right << std::setfill(' ') << std::setw(25) << str;
}

void	PhoneBook::print_right_padded(std::string str)
{
	std::cout << std::left << std::setfill(' ') << std::setw(25) << str;
}

std::string	PhoneBook::get_entry(std::string name)
{
	std::string	line;

	print_right_padded(name);
	if (name == "darkest_secret")
		std::cout << "🤫 ";
	else
		std::cout << "$ ";
	std::getline(std::cin, line);
	return (line);
}

bool	PhoneBook::check_add_phone(Contact user_input)
{
	if (!user_input.get_first_name().size())
		return (true);
	if (!user_input.get_last_name().size())
		return (true);
	if (!user_input.get_nick_name().size())
		return (true);
	if (!user_input.get_phone_number().size())
		return (true);
	if (!user_input.get_darkest_secret().size())
		return (true);
	return (false);
}

void	PhoneBook::main_loop(void)
{
	std::string	user_input;
	Contact		test;

	while (true)
	{
		std::getline(std::cin, user_input);
		if (std::cin.fail())
		{
			std::cout << "Ctrl-D pressed, exiting..\n";
			break ;
		}
		if (user_input == "SEARCH")
			search_phone_book();
		else if (user_input == "ADD")
			add_phone_book();
		else if (user_input == "EXIT")
			break ;
		else
			std::cout << "wrong input" << std::endl;
	}
}
