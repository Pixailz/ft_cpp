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
#include "Form.hpp"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << H_DEBUG << msg << std::endl;
}

void	test_exception(void)
{
	try {			// TOO HIGH GRADE
		Form exception_00("test_exception", 0, 150);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {			// TOO LOW GRADE
		Form exception_00("test_exception", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {			// EMPTY NAME
		Form exception_00("", 1, 150);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// try {			// BUREAUCRATE CAN'T SIGN
	// 	Form		exception_00("documents", 1, 150);
	// 	Bureaucrat	cadre_01("Pix", 75);

	// 	exception_00.be_signed(cadre_01);
	// }
	// catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	return ;
}

int	main(void)
{
	{		// EXCEPTION TEST
		test_exception();
	}
	{		// BASIC TEST
		Bureaucrat	cadre_01("Pix", 30);
		Form		form_01("Test_01", 149, 150);
		Form		form_02(form_01);
		Form 		form_03("test_03", 20, 20);

		std::cout << form_01 << std::endl;
		std::cout << form_02 << std::endl;

		form_01.be_signed(cadre_01);
		std::cout << form_01 << std::endl;
		std::cout << form_02 << std::endl;

		form_02 = form_01;
		std::cout << form_01 << std::endl;
		std::cout << form_02 << std::endl;
		cadre_01.sign_form(&form_03);
		cadre_01.sign_form(&form_01);
		std::cout << form_02 << std::endl;
		std::cout << form_03 << std::endl;
	}
	// {		// BASIC TEST
	// 	Bureaucrat	cadre_01("Pix", 30);
	// 	Form		form_01("Test_01", 149, 150);

	// 	std::cout << form_01 << std::endl;

	// 	cadre_01.sign_form(&form_01);
	// 	std::cout << form_01 << std::endl;
	// }
	return (0);
}
