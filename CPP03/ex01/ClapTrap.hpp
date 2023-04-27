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
#define CLAPTRAP_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */

# ifndef DEBUG
#  define DEBUG		1
# endif

#define WRONG_UINT ((unsigned int)-1)

class ClapTrap
{
protected:
	// VAR
	std::string _name;
	int _hp;  // health point
	int _mp;  // mana (energy)
	int _dmg; // attack dammage

	// OTHER FUNCTION
	virtual void i_identify_myself_as(void); // to not prevent on child
	virtual void attack(const std::string &target);

public:
	// CONSTRUCTOR
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);

	// DESTRUCTOR
	~ClapTrap(void);

	// OPERATOR FUNCTION
	ClapTrap &operator=(const ClapTrap &src);

	// SETTER
	void set_name(std::string name);
	void set_hp(int amount);
	void set_mp(int amount);
	void set_dmg(int amount);

	// GETTER
	std::string get_name(void);
	int get_hp(void);
	int get_mp(void);
	int get_dmg(void);

	// OTHER FUNCTION
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void baseAttack(const std::string &target);
};

void debug(std::string msg);

#endif // CLAPTRAP_CLASS
