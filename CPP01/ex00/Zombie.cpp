/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Zombie.cpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex00                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T01:21:51+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Zombie.hpp"

/*#BEGIN#________________________>#_|PUBLIC|_#<_____________________________##*/

/*#BEGIN#_____________________>#_|CONSTRUCTOR|_#<___________________________##*/

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

/*#END#_______________________<#_|CONSTRUCTOR|_#>___________________________##*/

/*#BEGIN#______________________>#_|DESTRUCTOR|_#<___________________________##*/

Zombie::~Zombie(void)
{
	std::cout << "Zombie class destroyed with name : "
			  << this->name << std::endl;
}

/*#END#________________________<#_|DESTRUCTOR|_#>___________________________##*/

/*#BEGIN#________________________>#_|SETTER|_#<_____________________________##*/

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

/*#END#__________________________<#_|SETTER|_#>_____________________________##*/

/*#BEGIN#________________________>#_|OTHER|_#<______________________________##*/

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*#END#__________________________<#_|OTHER|_#>______________________________##*/

/*#END#__________________________<#_|PUBLIC|_#>_____________________________##*/
