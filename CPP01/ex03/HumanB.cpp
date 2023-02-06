/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		HumanA.cpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex03                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <HumanB.hpp>
/****************
 * <object>		object
 * <function>	function()
 */

/*#BEGIN#_______________________>#_|PRIVATE|_#<_____________________________##*/

/*#BEGIN#________________________>#_|GETTER|_#<_____________________________##*/

std::string	HumanB::getName(void)
{
	return (_name);
}

/*#END#__________________________<#_|GETTER|_#>_____________________________##*/


/*#END#_________________________<#_|PRIVATE|_#>_____________________________##*/

/*#BEGIN#________________________>#_|PUBLIC|_#<_____________________________##*/

/*#BEGIN#_____________________>#_|CONSTRUCTOR|_#<___________________________##*/

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
}

/*#END#_______________________<#_|CONSTRUCTOR|_#>___________________________##*/

/*#BEGIN#______________________>#_|DESTRUCTOR|_#<___________________________##*/

HumanB::~HumanB(void) { }
//{
//	std::cout << "HumanB class destructed\n";
//}

/*#END#________________________<#_|DESTRUCTOR|_#>___________________________##*/

/*#BEGIN#________________________>#_|SETTER|_#<_____________________________##*/

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

/*#END#__________________________<#_|SETTER|_#>_____________________________##*/

/*#BEGIN#________________________>#_|GETTER|_#<_____________________________##*/

/*#END#__________________________<#_|GETTER|_#>_____________________________##*/

/*#BEGIN#________________________>#_|OTHER|_#<______________________________##*/

void	HumanB::attack(void)
{
	std::string	type;

	if (!_weapon)
		type = "";
	else
		type = _weapon->getType();
	if (!type.size())
		std::cout << getName()
				  << " attacks with bare hand, because doesn't have weapon"
				  << std::endl;
	else
		std::cout << getName() << " attacks with their " << type
				  << std::endl;
}

/*#END#__________________________<#_|OTHER|_#>______________________________##*/

/*#END#__________________________<#_|PUBLIC|_#>_____________________________##*/
