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

std::string	HumanB::getName(void)
{
	return (_name);
}

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB(void) { }
//{
//	std::cout << "HumanB class destructed\n";
//}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

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
