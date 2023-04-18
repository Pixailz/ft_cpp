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

# include <DiamondTrap.hpp>
/**
 * <object>		object
 * <function>	function()
 */

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	_name = name;
	ClapTrap::set_name(name + "_clap_name");
	_hp (FragTrap::get_hp());
	set_mp(ScavTrap::get_mp());
	set_dmg(FragTrap::get_dmg());

	i_identify_myself_as();
	std::cout << "class created" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	i_identify_myself_as();
	std::cout << "class destructed" << std::endl;
}

void	FragTrap::i_identify_myself_as(void)
{
	std::cout << "DiamonTrap (" << this->get_name() << ") : ";
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I'm " << get_name() << "My ClapTrap name is " << ClapTrap::get_name() << std::endl;
}
