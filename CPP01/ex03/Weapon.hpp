/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Weapon.hpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex03                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
/**
 * <object>	std::string
 */

class Weapon
{
	private:
		// VAR(S)
		std::string	_type;

		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		Weapon(void);
		Weapon(std::string type);

		// DESTRUCTOR(S)
		~Weapon(void);

		// SETTER(S) FUNCTION
		void				setType(std::string type);

		// GETTER(S) FUNCTION
		const std::string	&getType(void);

		// OTHER(S) FUNCTION
};

#endif // WEAPON_CLASS
