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

#include "main.h"

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

Base	*generate(void)
{
	std::ifstream	infile("/dev/urandom");
	char			random_char;

	if (infile.is_open())
		random_char = infile.get() % 3;
	infile.close();
	if (random_char == 1)
		return (new A);
	else if (random_char == 2)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	std::cout << "[" OR "*" RST "]";
	if (dynamic_cast<A*>(p))
		std::cout << H_A;
	else if (dynamic_cast<B*>(p))
		std::cout << H_B;
	else if (dynamic_cast<C*>(p))
		std::cout << H_C;
	else
		std::cout << H_U;
}

void	identify(Base &p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << H_A;
	}
	catch (std::exception &e) {
	try {
		dynamic_cast<B&>(p);
		std::cout << H_B;
	}
	catch (std::exception &e) {
	try {
		dynamic_cast<C&>(p);
		std::cout << H_C;
	}
	catch (std::exception &e) {
		std::cout << H_U;
	}}}
	std::cout << "[" OR "&" RST "]";
}

int	main(void)
{
	Base	*tmp;

	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			tmp = generate();
			identify(tmp);
			identify(*tmp);
			delete tmp;
		}
		std::cout << std::endl;
	}
	return (0);
}

// real	0m5.288s
// user	0m0.575s
// sys	0m3.244s
