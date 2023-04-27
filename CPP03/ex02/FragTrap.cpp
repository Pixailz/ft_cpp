/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ScavTrap.cpp                           | |_/ /___  __   ##*/
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


void	FragTrap::attack(const std::string target)
{
	this->i_identify_myself_as();
	ClapTrap::baseAttack(target);
}

void	FragTrap::i_identify_myself_as(void)
{
	std::cout << "FragTrap (" << this->get_name() << ") : ";
}

void	FragTrap::highFivesGuys(void)
{
	int current_mp = this->get_mp();

	this->i_identify_myself_as();
	if (current_mp > 19)
	{
		current_mp = current_mp - 20;
		this->set_mp(current_mp);
		std::cout << "has now " << current_mp << std::endl;
		i_identify_myself_as();
		std::cout << "HIGH FIVE GUYS ✋" << std::endl;

	}
	else
		std::cout << "cannot high five 😢. has " << current_mp \
			<< ", needed at least 20" << std::endl;
}
