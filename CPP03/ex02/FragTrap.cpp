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

# include <FragTrap.hpp>
/**
 * <object>		object
 * <function>	function()
 */

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	set_hp(100);
	set_mp(100);
	set_dmg(30);
	i_identify_myself_as();
	std::cout << "class created" << std::endl;
}

FragTrap::~FragTrap(void)
{
	i_identify_myself_as();
	std::cout << "class destructed" << std::endl;
}

void	FragTrap::i_identify_myself_as(void)
{
	std::cout << "FragTrap (" << this->get_name() << ") : ";
}

void	FragTrap::highFivesGuys(void)
{
	i_identify_myself_as();
	std::cout << "HIGH FIVE GUYS ✋" << std::endl;
}
