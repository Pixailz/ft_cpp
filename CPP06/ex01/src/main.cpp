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

#include "Serializer.hpp"

#define COL_INFO				"\x1b[20G"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

void	print_data(Data *src)
{
	std::cout << "Data->a_string:" << COL_INFO << src->a_string << std::endl;
	std::cout << "Data->a_number:" << COL_INFO << src->a_number << std::endl;
	std::cout << "Data->a_char:" << COL_INFO << src->a_char << std::endl;
}

int	main(void)
{
		// Data(std::string a_string, int a_number, char a_char);

	Data		*src = new Data;
	Data		*dst = NULL;
	uintptr_t	serialized;

	src->a_string = "test";
	src->a_number = 1;
	src->a_char = 'c';

	print_data(src);

	serialized = Serializer::serialize(src);

	std::cout << "serialized" << COL_INFO;
	std::cout << "0x" << std::hex << serialized << std::endl;

	dst = Serializer::deserialize(serialized);

	print_data(dst);

	delete dst;

	return (0);
}
