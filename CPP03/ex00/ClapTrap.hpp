/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ClapTrap.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */

# define DEBUG		1

# define WRONG_UINT	((unsigned int)-1)

class ClapTrap
{
	private:
		// VAR(S)
		std::string	_name;
		int			_hp;	// health point
		int			_mp;	// mana (energy)
		int			_dmg;	// attack dammage

		// OTHER(S) FUNCTION
	public:
		// CONSTRUCTOR(S)
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);

		// DESTRUCTOR(S)
		~ClapTrap(void);

		// OPERATOR(S) FUNCTION
		ClapTrap	&operator=(const ClapTrap &src);

		// OTHER(S) FUNCTION
		void		set_hp(int amount);
		void		set_mp(int amount);
		int			get_hp(void);
		int			get_dmg(void);
		int			get_mp(void);
		std::string	get_name(void);
		void		i_identify_myself_as(void);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_CLASS
