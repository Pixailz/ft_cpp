/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Brain.hpp                              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

# ifndef DEBUG
#  define DEBUG		1
# endif
# ifndef NB_IDEAS
#  define NB_IDEAS	100
# endif

class Brain
{
	private:
		// VAR(S)
		std::string	*_ideas[100];
		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		Brain(void);
		Brain(const Brain &copy);

		// DESTRUCTOR(S)
		~Brain(void);

		// OPERATOR(S) FUNCTION
		Brain	&operator=(const Brain &src);

		// SETTER(S)
		void	set_ideas(std::string ideas[]);

		// OTHER(S)
		void	say_ideas(void);
};

#endif // BRAIN_CLASS
