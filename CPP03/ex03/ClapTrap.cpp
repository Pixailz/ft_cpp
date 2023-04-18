/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ClapTrap.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <ClapTrap.hpp>
/**
 * <object>		object
 * <function>	function()
 */

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _mp(10), _dmg(1)
{
	i_identify_myself_as();
	std::cout << "class created" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	i_identify_myself_as();
	std::cout << "class destructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	i_identify_myself_as();
	std::cout << "class created (by copy)" << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	i_identify_myself_as();
	std::cout << "'=' " << src._name << std::endl ;
	_name = src._name;
	_hp = src._hp;
	_mp = src._mp;
	_dmg = src._dmg;
	return (*this);
}

void	ClapTrap::set_name(std::string name)
{
	_name = name;
}

void	ClapTrap::set_hp(int amount)
{
	_hp = amount;
}

void	ClapTrap::set_mp(int amount)
{
	_mp = amount;
}

void	ClapTrap::set_dmg(int amount)
{
	_dmg = amount;
}


std::string ClapTrap::get_name(void)
{
	return (_name);
}

int	ClapTrap::get_hp(void)
{
	return (_hp);
}

int	ClapTrap::get_dmg(void)
{
	return (_dmg);
}

int	ClapTrap::get_mp(void)
{
	return (_mp);
}


void	ClapTrap::i_identify_myself_as(void)
{
	std::cout << "ClapTrap (" << this->get_name() << ") : ";
}

void	ClapTrap::attack(const std::string &target)
{
	int	curr_mp;

	curr_mp = this->get_mp() - 1;
	this->i_identify_myself_as();
	if (curr_mp < 0)
		std::cout << "can't attack because it have no mp left" << std::endl;
	else
	{
		std::cout << "attacking " << target << ", causing " << this->get_dmg();
		std::cout << " points of damage!" << std::endl;
		this->set_mp(curr_mp);
		std::cout << "remaining mp : " << curr_mp << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	old_hp;
	int	new_hp;

	old_hp = this->get_hp();
	if (amount == WRONG_UINT)
	{
		std::cerr << "wrong number provided, defaulting to 0" << std::endl;
		amount = 0;
	}
	new_hp = old_hp - amount;
	new_hp = (new_hp < 0 ? 0 : new_hp);
	this->i_identify_myself_as();
	std::cout << "take " << amount << " damage point" << std::endl;
	std::cout << old_hp << " -> " << new_hp << std::endl;
	this->set_hp(new_hp);
	if (!new_hp)
	{
		this->i_identify_myself_as();
		std::cout << "died" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int	old_hp;
	int	new_hp;

	old_hp = this->get_hp();
	if (amount == WRONG_UINT)
	{
		std::cerr << "wrong number provided, defaulting to 0" << std::endl;
		amount = 0;
	}
	new_hp = old_hp + amount;
	this->i_identify_myself_as();
	std::cout << "get repaired by " << amount << " hp " ;
	std::cout << "(" << old_hp << " -> " << new_hp << ")" << std::endl;
	this->set_hp(new_hp);
}

