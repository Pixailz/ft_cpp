/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		HumanA.cpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex03                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <HumanA.hpp>
/****************
 * <object>		object
 * <function>	function()
 */

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon),
												   _name(name) {}

HumanA::~HumanA(void) { }
//{
//	std::cout << "HumanA class destructed\n";
//}

std::string	HumanA::getName(void)
{
	return (_name);
}

void	HumanA::attack(void)
{
	std::string	type;

	type = _weapon.getType();
	if (!type.size())
		std::cout << getName()
				  << " attacks with bare hand, because doesn't have weapon"
				  << std::endl;
	else
		std::cout << getName() << " attacks with their " << type
				  << std::endl;
}
