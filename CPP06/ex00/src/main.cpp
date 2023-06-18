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
	ScalarConverter	u;

	std::cout << std::endl << "CHARACTER" << std::endl;

	// GOOD
	u.convert("'a'");
	u.convert("\"a\"");
	u.convert("'\x90'");
	u.convert("'\xef'");

	// BAD
	u.convert("'a");
	u.convert("a'");
	u.convert("\"a");
	u.convert("a\"");
	u.convert("'a\"");
	u.convert("\"a'");
	u.convert("a");
}

void	test_int(void)
{
	ScalarConverter	u;

	std::cout << std::endl << "INTEGER" << std::endl;

	// GOOD
	u.convert("1234");
	u.convert("-1234");
	u.convert("+1234");
	u.convert("01234");

	// BAD
	u.convert("++1234");
	u.convert("+-1234");
	u.convert("A1234");
}

void	test_float(void)
{
	ScalarConverter	u;

	std::cout << std::endl << "FLOAT" << std::endl;

	// GOOD
	u.convert("1234.0f");
	u.convert("-1234.0f");
	u.convert("+1234.0f");
	u.convert("01234.0f");
	u.convert(".01234f");
	u.convert("+inff");
	u.convert("-inff");
	u.convert("nanf");

	// BAD
	u.convert("1234.0a");
	u.convert("++1234.0f");
	u.convert("+-1234.0f");
	u.convert("A1234.0f");
	u.convert("1234.f");
}

void	test_double(void)
{
	ScalarConverter	u;

	std::cout << std::endl << "DOUBLE" << std::endl;

	// GOOD
	u.convert("1234.0");
	u.convert("-1234.0");
	u.convert("+1234.0");
	u.convert("01234.0");
	u.convert(".01234");
	u.convert("+inf");
	u.convert("-inf");
	u.convert("nan");

	// BAD
	u.convert("++1234.0");
	u.convert("+-1234.0");
	u.convert("A1234.0");
	u.convert("1234.");
}

void	test_basic(void)
{
	ScalarConverter	u;

	u.convert("'a'");
	u.convert("1234");
	u.convert("1234.5678f");
	u.convert("1234.5678");

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
	if (ac == 2)
	{
		ScalarConverter	u;

		u.convert(av[1]);
	}
	else
		std::cerr << "Wrong args number" << std::endl;
	return (0);
}
