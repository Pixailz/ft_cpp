/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		megaphone.cpp                          | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP00-ex00                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−30T08:40:04+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include <iostream>
/****************
 * <object>		std::cout
 * <object>		std::endl
 * <function>	std::toupper()
 */

void	to_upper_str(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			to_upper_str(argv[i]);
			std::cout << argv[i];
		}
	}
	std::cout << std::endl;
	return (0);
}
