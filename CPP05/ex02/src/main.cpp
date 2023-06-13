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
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << H_CLASS << msg << std::endl;
}

int	main(void)
{
	{		// BASIC TEST
		Bureaucrat				cadre_01("pix", 1);
		Bureaucrat				user_01("user", 150);
		ShruberryCreationForm	Shrub_01("shrub");
		RobotomyRequestForm		Robot_01("roboto");
		PresidentialPardonForm	Pardon_01("pardon");

		std::cout << Shrub_01 << std::endl;

		cadre_01.sign_form(&Shrub_01);
		cadre_01.sign_form(&Robot_01);
		cadre_01.sign_form(&Pardon_01);
		std::cout << Shrub_01 << std::endl;
		std::cout << Robot_01 << std::endl;
		std::cout << Pardon_01 << std::endl;
		cadre_01.execute_form(&Shrub_01);
		cadre_01.execute_form(&Robot_01);
		cadre_01.execute_form(&Pardon_01);

		user_01.execute_form(&Shrub_01);
		user_01.execute_form(&Robot_01);
		user_01.execute_form(&Pardon_01);
	}
	{
		Bureaucrat			cadre("Pix", 1);
		RobotomyRequestForm	form("target");

		cadre.sign_form(&form);
		for (int i = 0; i < 20; i++)
			cadre.execute_form(&form);
	}
	return (0);
}
