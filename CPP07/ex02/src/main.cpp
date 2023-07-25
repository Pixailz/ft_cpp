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

#include <Array.hpp>
#include <stdlib.h>

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << H_DEBUG << msg << std::endl;
}

void	basic_test(void)
{
	{
		Array<int> arr(4);

		try {
			std::cout << arr[4] << std::endl;
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}

		arr[0] = 1;
		arr[1] = 5;
		arr[2] = -1;
		arr[3] = 150;

		std::cout << "arr[0] " << arr[0] << std::endl;
		std::cout << "arr[1] " << arr[1] << std::endl;
		std::cout << "arr[2] " << arr[2] << std::endl;
		std::cout << "arr[3] " << arr[3] << std::endl;
		std::cout << "arr.size() " << arr.size() << std::endl;
	}
}

#define MAX_VAL 750

int	subject_main(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

void	empty_array_test(void)
{
	Array<int> arr;

	try {
		std::cout << arr[0] << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	basic_test();
	empty_array_test();
	subject_main();
	return (0);
}
