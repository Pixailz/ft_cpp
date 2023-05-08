/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Animal.hpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

# ifndef DEBUG
#  define DEBUG		1
# endif
# ifndef MSG_POS
#  define MSG_POS	20	//ansi pos col (for pretty messages)
# endif


class Animal
{
	protected:
		std::string	_type;

	public:
		// CONSTRUCTOR(S)
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &copy);

		// DESTRUCTOR(S)
		// Should be virtual or an error message occur
		virtual	~Animal(void);

		// OPERATOR(S) FUNCTION
		Animal	&operator=(const Animal &src);

		std::string		get_type(void) const;
		void			set_type(std::string type);
		void			debug(std::string msg);
		void			introduce(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif // ANIMAL_CLASS
