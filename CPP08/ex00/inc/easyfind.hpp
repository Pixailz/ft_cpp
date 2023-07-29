/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.h                                 | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef EASYFIND_H
# define EASYFIND_H
/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

# include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */
#include <algorithm>
#include <exception>
#include <vector>
#include <deque>
#include <list>

template<typename T>
typename T::iterator easyfind(T & container, int toFind)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw (std::out_of_range("iterator not found"));
	return (it);
}

#endif // EASYFIND_H
