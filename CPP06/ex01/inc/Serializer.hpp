/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Serializer.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

#include <stdint.h>
/**
 * <type>		uintptr_t
 */

struct Data
{
	std::string	a_string;
	int			a_number;
	char		a_char;
};

# ifndef DEBUG
#  define DEBUG					1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD				420
# endif

# ifndef VERBOSE
#  define VERBOSE				1
# endif

void	debug(std::string msg);

class Serializer
{
	private:
		// VAR

		// OTHER FUNCTION

	public:
		// CONSTRUCTOR
		Serializer(void);
		Serializer(const Serializer &copy);

		// DESTRUCTOR
		~Serializer(void);

		// OPERATOR
		Serializer	&operator=(const Serializer &src);

		// EXCEPTION

		// SETTER

		// GETTER

		// OTHER
		static uintptr_t	serialize(Data* to_serialize);
		static Data*		deserialize(uintptr_t to_serialize);
};

#endif // SERIALIZER_CLASS
