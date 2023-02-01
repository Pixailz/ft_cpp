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

/*#BEGIN#_______________________>#_|PRIVATE|_#<_____________________________##*/



/*#END#_________________________<#_|PRIVATE|_#>_____________________________##*/

/*#BEGIN#________________________>#_|PUBLIC|_#<_____________________________##*/

/*#BEGIN#_____________________>#_|CONSTRUCTOR|_#<___________________________##*/


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

/*#END#_______________________<#_|CONSTRUCTOR|_#>___________________________##*/

/*#BEGIN#______________________>#_|DESTRUCTOR|_#<___________________________##*/

Weapon::~Weapon(void) { }
//{
//	std::cout << "Weapon class destructed\n";
//}

/*#END#________________________<#_|DESTRUCTOR|_#>___________________________##*/

/*#BEGIN#________________________>#_|SETTER|_#<_____________________________##*/

void	Weapon::setType(std::string type)
{
	_type = type;
}

/*#END#__________________________<#_|SETTER|_#>_____________________________##*/

/*#BEGIN#________________________>#_|GETTER|_#<_____________________________##*/

const std::string	&Weapon::getType(void)
{
	return (_type);
}

/*#END#__________________________<#_|GETTER|_#>_____________________________##*/

/*#BEGIN#________________________>#_|OTHER|_#<______________________________##*/



/*#END#__________________________<#_|OTHER|_#>______________________________##*/

/*#END#__________________________<#_|PUBLIC|_#>_____________________________##*/
