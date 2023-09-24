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

#include "main.h"

enum err {
	ERR_NOT_ENOUGHT_ARG = 1,
	ERR_ARG_NOT_GOOD_FILE,
	ERR_CSV_NOT_GOOD_FILE,
};

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

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Not enought args" << std::endl;
		return (ERR_NOT_ENOUGHT_ARG);
	}
	if (is_not_a_good_file(av[1])) {
		std::cerr << av[1] << " is not a good file" << std::endl;
		return (ERR_ARG_NOT_GOOD_FILE);
	}
	if (is_not_a_good_file("data.csv")) {
		std::cerr << "data.csv not found or is not a good file" << std::endl;
		return (ERR_CSV_NOT_GOOD_FILE);
	}

	return (0);
}
