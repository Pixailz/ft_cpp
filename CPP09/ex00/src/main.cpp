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

#include "BitcoinExchange.hpp"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

bool is_not_a_good_file(std::string filename)
{
	std::ifstream	test(filename.c_str());
	bool			is_open = test.is_open();

	if (is_open) test.close();
	return (!is_open);
}

void	err(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

void	err(std::string title, std::string msg)
{
	std::cerr << "Error: " << title << " " << msg << std::endl;
}

void	err(std::string title, std::string msg, int nb_line)
{
	std::cerr << "Error: " << title << " " << msg << " " << nb_line << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2) {
		err("Not enought args");
		return (ERR_NOT_ENOUGHT_ARG);
	}
	if (is_not_a_good_file(av[1])) {
		err(av[1], "isn't a good file");
		return (ERR_ARG_NOT_GOOD_FILE);
	}
	if (is_not_a_good_file(DATA_FILE)) {
		err(DATA_FILE, "isn't a good file");
		return (ERR_DATA_NOT_GOOD_FILE);
	}
	BitcoinExchange test(av[1]);

	return (0);
}

