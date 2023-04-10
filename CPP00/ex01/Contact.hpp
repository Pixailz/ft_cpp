/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Contact.hpp                            | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP00-ex01                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef CONTACT_CLASS
# define CONTACT_CLASS

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

#include <iomanip>
/**
 * <function>	std::setw()
 * <function>	std::setfill()
 */

#include <string>
/**
 * <object>		std::string
 * <function>	std::string::clear()
 */

class Contact
{
	private:
		// VAR(S)
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

		// INTERNAL FUNCTION(S)
		std::string	get_formated(std::string content, int length);

	public:
		// CONSTRUCTOR(S)
		Contact(void);

		// DESTRUCTOR(S)
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
