/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−06−15T19:42:03+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "ScalarConverter.hpp"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

void	test_char(void)
{
	std::cout << std::endl << "CHARACTER" << std::endl;

	// GOOD
	ScalarConverter::convert("'a'");
	ScalarConverter::convert("\"a\"");
	ScalarConverter::convert("'\x90'");
	ScalarConverter::convert("'\xef'");
	ScalarConverter::convert("'\xff'");

	// BAD
	ScalarConverter::convert("'a");
	ScalarConverter::convert("a'");
	ScalarConverter::convert("\"a");
	ScalarConverter::convert("a\"");
	ScalarConverter::convert("'a\"");
	ScalarConverter::convert("\"a'");
	ScalarConverter::convert("a");
}

void	test_int(void)
{
	std::cout << std::endl << "INTEGER" << std::endl;

	// GOOD
	ScalarConverter::convert("1234");
	ScalarConverter::convert("-1234");
	ScalarConverter::convert("+1234");
	ScalarConverter::convert("01234");

	// BAD
	ScalarConverter::convert("++1234");
	ScalarConverter::convert("+-1234");
	ScalarConverter::convert("A1234");
}

void	test_float(void)
{
	std::cout << std::endl << "FLOAT" << std::endl;

	// GOOD
	ScalarConverter::convert("1234.0f");
	ScalarConverter::convert("-1234.0f");
	ScalarConverter::convert("+1234.0f");
	ScalarConverter::convert("01234.0f");
	ScalarConverter::convert(".01234f");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("1234.f");

	// BAD
	ScalarConverter::convert("1234..f");
	ScalarConverter::convert("1234.0a");
	ScalarConverter::convert("++1234.0f");
	ScalarConverter::convert("+-1234.0f");
	ScalarConverter::convert("A1234.0f");
}

void	test_double(void)
{
	std::cout << std::endl << "DOUBLE" << std::endl;

	// GOOD
	ScalarConverter::convert("1234.0");
	ScalarConverter::convert("-1234.0");
	ScalarConverter::convert("+1234.0");
	ScalarConverter::convert("01234.0");
	ScalarConverter::convert(".01234");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("1234.");

	// BAD
	ScalarConverter::convert("1234..");
	ScalarConverter::convert("++1234.0");
	ScalarConverter::convert("+-1234.0");
	ScalarConverter::convert("A1234.0");
}

void	test_basic(void)
{
	ScalarConverter::convert("'a'");
	ScalarConverter::convert("1234");
	ScalarConverter::convert("1234.5678f");
	ScalarConverter::convert("1234.5678");

}

void	all_test(void)
{
	test_basic();
	test_char();
	test_int();
	test_float();
	test_double();
}

int	main(int ac, char **av)
{
	// all_test();
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cerr << "Wrong args number" << std::endl;
	return (0);
}
