/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Harl.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cin
 * <function>	std::cin::fail()
 * <object>		std::endl
 */

# define	NB_FUNCTION					4

class Harl
{
	private:
		// VAR(S)

		// OTHER(S) FUNCTION
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		// CONSTRUCTOR(S)
		Harl(void);

		// DESTRUCTOR(S)
		~Harl(void);

		// OTHER(S) FUNCTION
		void	complain(std::string level);
};

#endif // HARL_CLASS
