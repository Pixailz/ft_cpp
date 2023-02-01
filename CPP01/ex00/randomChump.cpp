/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		randomChump.cpp                        | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex00                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T01:21:23+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie random_zombie;

	random_zombie.set_name(name);
	random_zombie.announce();
}
