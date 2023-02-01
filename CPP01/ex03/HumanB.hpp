/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		HumanB.hpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex03                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef HUMANB_HPP
# define HUMANB_HPP

/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

#include "Weapon.hpp"

#include <string>
/**
 * <object>	std::string
 */

#include <iostream>
/**
 * <object>	std::cout
 * <object>	std::endl
 */

/*#END#_______________________<#_|DEPENDENCIES|_#>__________________________##*/

class HumanB
{
	private:
		// VAR(S)
		Weapon*		_weapon;
		std::string	_name;

		// GETTER(S) FUNCTION
		std::string	getName(void);

		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		HumanB(std::string name);

		// DESTRUCTOR(S)
		~HumanB(void);

		// SETTER(S) FUNCTION
		void	setWeapon(Weapon &weapon);

		// OTHER(S) FUNCTION
		void	attack(void);
};

/*#BEGIN#________________________>#_|TYPEDEF|_#<____________________________##*/

/*#END#__________________________<#_|TYPEDEF|_#>____________________________##*/

/*#BEGIN#_____________________>#_|PROTOTYPE(S)|_#<__________________________##*/

/*#END#_______________________<#_|PROTOTYPE(S)|_#>__________________________##*/

#endif // HUMANA_CLASS
