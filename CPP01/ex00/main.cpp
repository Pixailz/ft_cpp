/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex00                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T00:57:43+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main(void)
{
	Zombie	*stack_zombie;

	// don't allocate juste use heap in function of the class
	randomChump("Joy");

	// separate two functions
	std::cout << std::endl;

	// allocate
	stack_zombie = newZombie("Brainless");

	// use
	stack_zombie->announce();

	// free
	delete(stack_zombie);

	return (0);
}
