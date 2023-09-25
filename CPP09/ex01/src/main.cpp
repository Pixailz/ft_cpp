/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−06−18T05:56:28+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "RPN.hpp"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

void	err(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

void	err(std::string title, std::string msg)
{
	std::cerr << "Error: " << title << " " << msg << std::endl;
}

void	err(std::string title, int char_pos)
{
	std::cerr << "Error: " << title << " " << char_pos << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		err("wrong number of args");
		return (ERR_ARG);
	}
	RPN	test(av[1]);

	test.calculate();
	return (0);
}
