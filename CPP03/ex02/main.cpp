/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−04−18T00:20:29+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include <FragTrap.hpp>

int	main(void)
{
	FragTrap	P1("Player_01");
	FragTrap	P2("Player_02");
	FragTrap	P3("Player_03");
	int			nb_round = 11;

	P2 = P3;

	P3.highFivesGuys();
	while (nb_round)
	{
		P1.attack(P2.get_name());
		P2.takeDamage(P1.get_dmg());
		if (nb_round % 6)
			P3.highFivesGuys();
		P2.beRepaired(30);
		nb_round--;
	}
	return (0);
}
