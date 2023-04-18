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

#include <ScavTrap.hpp>

int	main(void)
{
	ScavTrap	P1("Player_01");
	ScavTrap	P2("Player_02");
	ScavTrap	P3("Player_03");
	int			nb_round = 11;

	P2 = P3;

	while (nb_round)
	{
		P1.attack(P2.get_name());
		P2.takeDamage(P1.get_dmg());
		if (nb_round % 3)
			P3.guardGate();
		P2.beRepaired(20);
		nb_round--;
	}
	return (0);
}
