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

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << H_DEBUG << msg << std::endl;
}

void	test_exception(void)
{
	try {			// EMPTY NAME
		Bureaucrat exception_00("");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {			// this one will not fail, but as it's in the try scope
					// it will not be available outside
		Bureaucrat exception_01("SomeName", 99);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {			// TOO LOW GRADE
		Bureaucrat	exception_00("Random Name", -1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {			// TO HIGH GRADE
		Bureaucrat	exception_00("Random Name", 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {			// DEC TOO LOW GRADE
		Bureaucrat	exception_00("Random Name", 150);

		exception_00.dec_grade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {			// INC TOO HIGH GRADE
		Bureaucrat	exception_00("Random Name", 1);

		exception_00.inc_grade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	{	// BASIC TEST
		Bureaucrat	cadre_01("Sebastien");
		Bureaucrat	cadre_02("Phillipe", 1);

		cadre_01.inc_grade();
		cadre_02.dec_grade();

		std::cout << cadre_01 << std::endl;
		std::cout << cadre_02 << std::endl;
	}
	{	// EXCEPTION TEST
		test_exception();
	}
	return (0);
}
