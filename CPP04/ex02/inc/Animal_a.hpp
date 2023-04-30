/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Animal_a.hpp                           | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef ANIMAL_A_HPP
# define ANIMAL_A_HPP

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


class Animal_a
{
	protected:
		std::string	_type;

	public:
		// CONSTRUCTOR(S)
		Animal_a(void);
		Animal_a(std::string type);
		Animal_a(const Animal_a &copy);

		// DESTRUCTOR(S)
		// Should be virtual or an error message occur
		virtual	~Animal_a(void);

		// OPERATOR(S) FUNCTION
		Animal_a	&operator=(const Animal_a &src);

		std::string		get_type(void) const;
		void			set_type(std::string type);
		void			debug(std::string msg);
		void			introduce(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif // ANIMAL_A_CLASS
