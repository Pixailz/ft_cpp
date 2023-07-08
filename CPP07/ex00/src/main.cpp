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

#include <whatever.h>

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

void	test_all_swap(void)
{
	std::cout << "test swap" << std::endl;
	{ int			a = 5,		b = 25;		test_swap(a, b); }
	{ short			a = 5,		b = 25;		test_swap(a, b); }
	{ char			a = 'A',	b = 'B';	test_swap(a, b); }
	{ unsigned char	a = 'A',	b = 'B';	test_swap(a, b); }
	{ std::string	a = "AAAA",	b = "BBBB";	test_swap(a, b); }
	std::cout << std::endl;
}

void	test_all_min(void)
{
	std::cout << "test min" << std::endl;
	{ int			a = 5,		b = 25;		test_min(a, b); }
	{ short			a = 5,		b = 25;		test_min(a, b); }
	{ char			a = 'A',	b = 'B';	test_min(a, b); }
	{ unsigned char	a = 'A',	b = 'B';	test_min(a, b); }
	{ std::string	a = "AAAA",	b = "BBBB";	test_min(a, b); }
	std::cout << std::endl;
}

void	test_all_max(void)
{
	std::cout << "test max" << std::endl;
	{ int			a = 5,		b = 25;		test_max(a, b); }
	{ short			a = 5,		b = 25;		test_max(a, b); }
	{ char			a = 'A',	b = 'B';	test_max(a, b); }
	{ unsigned char	a = 'A',	b = 'B';	test_max(a, b); }
	{ std::string	a = "AAAA",	b = "BBBB";	test_max(a, b); }
	std::cout << std::endl;
}

void	test_subject(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void	test_all(void)
{
	test_all_swap();
	test_all_min();
	test_all_max();
	test_subject();
}

int	main(void)
{
	test_all();
	return (0);
}
