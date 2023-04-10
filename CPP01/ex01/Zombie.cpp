/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Zombie.cpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex01                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T17:43:51+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name.clear();
	std::cout << "Zombie class created\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie class created with name : "
			  << name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie class destroyed with name : "
			  << this->name << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
