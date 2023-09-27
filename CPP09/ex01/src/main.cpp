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
	std::cerr << H_ERROR << msg << std::endl;
}

void	err(std::string title, std::string msg)
{
	std::cerr << H_ERROR << title << " " << msg << std::endl;
}

void	err(std::string title, int char_pos)
{
	std::cerr << H_ERROR << title << " " << char_pos << std::endl;
}

void	test_one(std::string expr)
{
	RPN test(expr);

	std::cout	<< H_DEBUG << "test launched with the following expression: "
				<< '"' << expr << '"' << std::endl;
	try {
		test.calculate();
	}
	catch (std::exception &e) {
		err(e.what());
	}
	std::cout << std::endl;
}

void	test_good(void)
{
	// SUBJECT
	test_one("8 9 * 9 - 9 - 9 - 4 - 1 +");
	test_one("7 7 * 7 -");
	test_one("1 2 * 2 / 2 * 2 4 - +");

	// CUSTOM
	test_one("3 2 /"); // with a stack of double display the decimal form
	test_one("      1 2 * 2 / 2 * 2 4 - +");
	test_one("      1 2 * 2 / 2 * 2 4 - +                 ");
	test_one("1 2 3 4 + + +");
	test_one("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 + + + + + + + + + + + + + + + + +");
	test_one("9 ");
}

void	test_wrong(void)
{
	// SUBJECT
	test_one("(1 + 1)");

	// CUSTOM
		// BASIC
	test_one("+ 1 2 ");
	test_one("   a  1 2 * 2 / 2 * 2 4 - +");
	test_one("1 3 2 35 8");
	test_one("1 2 3 4 5 + + +");
	test_one("1 2 3 4 + + + +");

		// OVERFLOW / UNDERFLOW
	test_one("9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 * * * * * * * * * * * * * * * * *");
	test_one("9 9 9 9 9 9 9 9 9 1 9 - * * * * * * * * *");
}

void	test(void)
{ test_good(); test_wrong(); }

int	main(int ac, char **av)
{
	{
		// test();
		// test_good();
		// test_wrong();
	}
	if (ac != 2)
	{
		err("wrong number of args");
		return (ERR_ARG);
	}
	RPN	test(av[1]);

	try {
		test.calculate();
	}
	catch (std::exception &e) {
		err(e.what());
	}
	return (0);
}
