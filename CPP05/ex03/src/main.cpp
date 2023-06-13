/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−04−18T00:20:29+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << H_CLASS << msg << std::endl;
}

int	main(void)
{
	{
		Bureaucrat	cadre_01("test", 1);
		Intern someRandomIntern;
		AForm *rrf;


		for (int i = 0; i < 10; i++)
		{
			rrf = someRandomIntern.make_form("Robotomy", "Bender");

			cadre_01.sign_form(rrf);
			cadre_01.execute_form(rrf);

			delete rrf;
		}
	}
	return (0);
}
