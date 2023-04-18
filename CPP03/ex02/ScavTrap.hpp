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

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <ClapTrap.hpp>
/**
 * <class>		ClapTrap()
 */

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

# define DEBUG		1

class ScavTrap : public ClapTrap
{
	private:
		virtual void	i_identify_myself_as(void);
		bool			_guard_gate_mode;

		// SETTER
		void	toggle_guard_gate_mode(void);

		// GETTER
		bool	get_guard_gate_mode(void);

	public:
		// CONSTRUCTOR / DESTRUCTOR / COPY CONSTRUCTOR
		ScavTrap(std::string name);
		~ScavTrap(void);
		void	guardGate(void);

};

#endif // SCAVTRAP_CLASS
