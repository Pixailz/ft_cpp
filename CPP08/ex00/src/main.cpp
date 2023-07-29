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

#include <easyfind.hpp>

void	test_vector(void)
{
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(12);
	vec.push_back(10);
	vec.push_back(25);

	std::vector<int>::iterator founded = easyfind(vec, 12);
	std::cout << "Found " << *founded << std::endl;

	try {
		std::vector<int>::iterator founded = easyfind(vec, 13);
		std::cout << "Vector Found " << *founded << std::endl;}
	catch (std::exception &e){
		std::cerr << "Vector Error " << e.what() << std::endl;
	}
}

void	test_deque(void)
{
	std::deque<int> deq;

	deq.push_back(5);
	deq.push_back(12);
	deq.push_front(10);
	deq.push_front(25);

	std::deque<int>::iterator founded = easyfind(deq, 12);
	std::cout << "Found " << *founded << std::endl;

	try {
		std::deque<int>::iterator founded = easyfind(deq, 13);
		std::cout << "Deque Found " << *founded << std::endl;}
	catch (std::exception &e){
		std::cerr << "Deque Error " << e.what() << std::endl;
	}
}

void	test_list(void)
{
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(12);
	lst.push_front(10);
	lst.push_front(25);

	std::list<int>::iterator founded = easyfind(lst, 12);
	std::cout << "Found " << *founded << std::endl;

	try {
		std::list<int>::iterator founded = easyfind(lst, 13);
		std::cout << "List Found " << *founded << std::endl;}
	catch (std::exception &e){
		std::cerr << "List Error " << e.what() << std::endl;
	}
}

void	test_all(void)
{
	test_vector();
	test_deque();
	test_list();
}

int	main(void)
{
	test_all();
	return (0);
}
