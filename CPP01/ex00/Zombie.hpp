/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Zombie.hpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex00                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <string>
/**
 * <object>	std::string
 */

# include <iostream>
/**
 * <object>	std::cout
 * <object>	std::endl
 */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	private:
		// VAR(S)
		std::string	name;

		// PRIVATE FUNCTION(S)

	public:
		// CONSTRUCTOR(S)
		Zombie(void);
		Zombie(std::string name);

		// DESTRUCTOR(S)
		~Zombie(void);

		// SETTER(S)
		void	set_name(std::string name);

		// OTHERS(S)
		void	announce(void);

};

# endif // ZOMBIE_CLASS
