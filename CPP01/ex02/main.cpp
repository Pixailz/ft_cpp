/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex02                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T02:32:52+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include <string>
/**
 * <object>	std::string
 */

#include <iostream>
/**
 * <object>	std::cout
 */

int	main(void)
{
	std::string	string_variable = std::string("HI THIS IS BRAIN");
	std::string	*ptr_variable = &string_variable;
	std::string	&ref_variable = string_variable;

	std::cout << "addresse of string_variable : " << &string_variable
			  << std::endl;
	std::cout << "addresse of ptr_variable : " << &ptr_variable
			  << std::endl;
	std::cout << "addresse of ref_variable : " << &ref_variable
			  << std::endl << std::endl;

	std::cout << "value of string_variable : " << string_variable
			  << std::endl;
	std::cout << "value of ptr_variable : " << ptr_variable
			  << std::endl;
	std::cout << "value of ref_variable : " << ref_variable
			  << std::endl;
	return (0);
}

// g++ -Wall -Werror -Wextra --std=c++98 -g3 main.cpp -o prog && ./prog
