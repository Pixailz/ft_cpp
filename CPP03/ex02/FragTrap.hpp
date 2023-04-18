/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ScavTrap.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <ClapTrap.hpp>
/**
 * ClapTrap()
 */

#include <iostream>
/**
 * std::cout
 * std::endl
 */

# define DEBUG		1

class FragTrap : public ClapTrap
{
	private:
		virtual void	i_identify_myself_as(void);

	public:
		// CONSTRUCTOR / DESTRUCTOR / COPY CONSTRUCTOR
		FragTrap(std::string name);
		~FragTrap(void);

		// OTHER
		void	highFivesGuys(void);
};

#endif // FRAGTRAP_CLASS
