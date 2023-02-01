/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		zombieHorde.cpp                        | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex01                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T02:32:19+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Zombie.hpp"

void	zombieHordeDelete(Zombie *horde)
{
	delete [] horde;
}

Zombie	*zombieHorde(int size, std::string name)
{
	Zombie	*new_zombie_horde;

	new_zombie_horde = new Zombie[size];
	for (int i = 0; i < size; i++)
		new_zombie_horde[i].set_name(name);
	return (new_zombie_horde);
}
