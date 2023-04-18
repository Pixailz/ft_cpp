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

#include <ClapTrap.hpp>

int	main(void)
{
	ClapTrap	P1("Player_01");
	ClapTrap	P2("Player_02");
	int			nb_round = 11;

	P1.beRepaired(-1);		// repaired by a wrong number;
	P1.takeDamage(-1);		// take damage by a wrong number;
	while (nb_round)
	{
		P1.attack(P2.get_name());
		P2.takeDamage(P1.get_dmg());
		P2.beRepaired(1);
		nb_round--;
	}
	return (0);
}
