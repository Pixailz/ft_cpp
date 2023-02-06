/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex03                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T02:35:38+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#include <iostream>
/**
 * <object>	std::cout
 * <object>	std::endl
 */

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}

// #include <iostream>
/**
 * <object>	std::cout
 * <object>	std::endl
 */

// int	main(void)
// {
// 	Weapon		test;
// 	std::string	&type_change = (std::string &)test.getType();
// 	std::string	&type_print = (std::string &)test.getType();

// 	test.setType("test");
// 	std::cout << type_print << std::endl;
// 	type_change = "test2";
// 	std::cout << type_print << std::endl;
// 	return (0);
// }
