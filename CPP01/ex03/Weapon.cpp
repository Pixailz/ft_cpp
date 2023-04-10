/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Weapon.cpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex03                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Weapon.hpp>

Weapon::Weapon(void) { }
//{
//	std::cout << "Weapon class created\n";
//}

Weapon::Weapon(std::string type)
{
	_type = type;
}
//{
//	std::cout << "Weapon class created\n";
//}

Weapon::~Weapon(void) { }
//{
//	std::cout << "Weapon class destructed\n";
//}

void	Weapon::setType(std::string type)
{
	_type = type;
}

const std::string	&Weapon::getType(void)
{
	return (_type);
}
