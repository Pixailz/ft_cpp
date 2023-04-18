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

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <FragTrap.hpp>
#include <ScavTrap.hpp>
/**
 * all that Claptrap classes
 */

#include <iostream>
/**
 * std::cout
 * std::endl
 */

# define DEBUG		1

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
		virtual void	i_identify_myself_as(void);

	public:
		// CONSTRUCTOR / DESTRUCTOR / COPY CONSTRUCTOR
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		using ScavTrap::attack;
		void			whoAmI(void);
};

#endif // FRAGTRAP_CLASS
