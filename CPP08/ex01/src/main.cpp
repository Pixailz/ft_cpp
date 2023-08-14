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

#include <Span.hpp>

#include <string>
// atoi()

bool	compare_int(int n1, int n2);

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

void	test_subject(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_basic(void)
{
	Span sp = Span(4);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	try {
		sp.addNumber(11);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_all(void)
{
	test_subject();
	test_basic();
}

int	get_random_int(void)
{
	std::ifstream	infile("/dev/urandom");
	unsigned int	random_int;

	if (infile.is_open())
	{
		for (int i = 0; i < 4; i++)
			random_int = random_int + (infile.get() << i * 8);
		infile.close();
	}
	return (random_int);
}

void	print_list(std::list<int> list)
{
	size_t	ite = 1;

	std::cout << H_DEBUG << "vanilla list" << std::endl;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << H_DEBUG << "[" << ite++ << "] " << *it << std::endl;
	list.sort(compare_int);
	ite = 1;
	std::cout << H_DEBUG << "sorted list" << std::endl;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << H_DEBUG << "[" << ite++ << "] " << *it << std::endl;
}

void	test_intensive(size_t len, size_t nb_test)
{
	std::list<int>	random_list;
	std::ofstream	outfile("result");

	if (len < 2)
	{
		std::cout << "len too small" << std::endl;
		return ;
	}
	for (size_t i = 0; i < nb_test; i++)
	{
		{
			Span	span = Span(len);
			size_t	ite = 0;
			size_t	shortest;
			size_t	longest;

			random_list.clear();
			std::cout << "[" << i << "] " << "generating random number" << std::endl;
			for (int j = len; j > 0; j--)
				random_list.push_back(get_random_int());
			std::cout << "[" << i << "] " << "adding number to span" << std::endl;
			for (std::list<int>::iterator it = random_list.begin(); it != random_list.end(); it++)
				span.addNumber(*it);
			std::cout << "[" << i << "] " << "starting shortest" << std::endl;
			shortest = span.shortestSpan();
			std::cout << "[" << i << "] " << "starting longest" << std::endl;
			longest = span.longestSpan();
			std::cout << H_DEBUG << "[" << i << "] Shortest span " << shortest << std::endl;
			std::cout << H_DEBUG << "[" << i << "] Longest span  " << longest << std::endl;
			random_list.sort(compare_int);
			for (std::list<int>::iterator it = random_list.begin(); it != random_list.end(); it++)
				outfile << "[" << i << "][" << ++ite << "] " << *it << std::endl;
			outfile << "[" << i << "] Shortest span " << shortest << std::endl;
			outfile << "[" << i << "] Longest span  " << longest << std::endl;
			outfile << std::endl;
		}
	}
	outfile.close();
}

void	usage(char *prog_name)
{
	std::cout << prog_name << " : len nb_test" << std::endl
		<< "    len        number of int in the span" << std::endl
		<< "    nb_test    iteration to do with the len" << std::endl;
}

int	main(int ac, char **av)
{

	if (ac == 1)
		test_all();
	else if (ac == 3)
		test_intensive(atoi(av[1]),atoi(av[2]));
	else
	{
		usage(av[0]);
		return (1);
	}
	return (0);
}
