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

# include <ScavTrap.hpp>
/**
 * <object>		object
 * <function>	function()
 */

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	set_hp(100);
	set_mp(50);
	set_dmg(20);
	_guard_gate_mode = false;
	i_identify_myself_as();
	std::cout << "class created" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	i_identify_myself_as();
	std::cout << "class destructed" << std::endl;
}

void	ScavTrap::attack(const std::string target)
{
	this->i_identify_myself_as();
	ClapTrap::baseAttack(target);
}

void	ScavTrap::i_identify_myself_as(void)
{
	std::cout << "ScavTrap (" << this->get_name() << ") : ";
}

void	ScavTrap::toggle_guard_gate_mode(void)
{
	int current_mp = this->get_mp() - 2;

	this->_guard_gate_mode = !this->_guard_gate_mode;
	this->set_mp(current_mp);
	this->i_identify_myself_as();
	std::cout << "has now " << current_mp << std::endl;
}

bool	ScavTrap::get_guard_gate_mode(void)
{
	return (_guard_gate_mode);
}

void	ScavTrap::guardGate(void)
{
	int	current_mp = this->get_mp();

	i_identify_myself_as();
	if (current_mp > 1)
	{
		std::cout << (get_guard_gate_mode() ? "is no longer" : "is now") \
			<< " in Gate keeper mode" << std::endl;
		toggle_guard_gate_mode();
	}
	else
		std::cout << "cannot change guard mode. has " << current_mp \
			<< ", needed at least 2" << std::endl;
}
