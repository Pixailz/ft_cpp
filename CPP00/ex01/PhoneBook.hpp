/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		PhoneBook.hpp                          | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP00-ex01                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

# include "Contact.hpp"

# include <cstdlib>
/**
 * <function>	strtol()
 */

#include <iostream>
/**
 * <function>	std::cin.fail()
 * <object>		std::cout
 * <object>		std::cin
 * <object>		std::endl
 */

#include <iomanip>
/**
 * <object>		std::right
 * <object>		std::left
 * <function>	std::setw()
 * <function>	std::setfill()
 */

#include <string>
/**
 * <object>		std::string
 * <function>	std::string::size()
 * <function>	std::string::getline()
 * <function>	std::string::c_str()
 */

/*#END#_______________________<#_|DEPENDENCIES|_#>__________________________##*/

/*#BEGIN#________________________>#_|CONFIG|_#<_____________________________##*/

# define PHONE_BOOK_SIZE		8

/*#END#__________________________<#_|CONFIG|_#>_____________________________##*/

class PhoneBook
{
	private:
		// VAR(S)
		Contact	phone_book[PHONE_BOOK_SIZE];
		size_t	nb_phone_book;

		// INTERNAL FUNCTION(S)
		// SETTER
		void		add_phone_book(void);
		void		add_phone_book_entry(Contact entry);
		void		update_index(void);

		// GETTER
		void		search_phone_book(void);
		void		print_all_entry(void);
		void		print_left_padded(std::string str);
		void		print_right_padded(std::string str);

		// UTILS
		bool		check_add_phone(Contact user_input);
		std::string	get_entry(std::string name);

	public:
		// CONSTRUCTOR(S)
		PhoneBook(void);

		// DESTRUCTOR(S)
		~PhoneBook(void);

		// EXTERNAL FUNCTION(S)
		void		main_loop(void);
};

# endif // PHONEBOOK_CLASS
