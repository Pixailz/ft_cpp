/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		whatever.h                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef WHATEVER_H
# define WHATEVER_H
/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

#include <string>
/**
 * <object>	std::string()
 */
#include <iostream>
/**
 * <object>	std::cout()
 * <object>	std::endl()
 */

# ifndef	DEBUG
#  define	DEBUG				1
# endif

# ifndef	DEBUG_FD
#  define	DEBUG_FD			420
# endif

# ifndef	VERBOSE
#  define	VERBOSE				1
# endif

# define	ANSI_ESC			"\x1b["
# define	R					ANSI_ESC "38:2::192:0:0m"
# define	G					ANSI_ESC "38:2::0:192:0m"
# define	B					ANSI_ESC "38:2::0:64:192m"
# define	COL_INFO			ANSI_ESC "11G"
# define	COL_INFO_2			ANSI_ESC "25G"
# define	RST					ANSI_ESC "0m"

# define	H_CLASS				"[" G "CLASS" RST "] → "
# define	H_DEBUG				"[" B "DEBUG" RST "] → "
# define	H_ERROR				"[" R "ERROR" RST "] → "

// mandatory
template <typename T>
void swap(T & a, T & b)
{ T tmp; tmp = a; a = b; b = tmp; }

template <typename T>
T & min(T & a, T & b)
{ return (a < b ? a : b); }

template <typename T>
T & max(T & a, T & b)
{ return (a > b ? a : b); }

// extra
template <typename T>
void print_a_b(T & a, T & b)
{
	std::cout << "[a:" << a << "]";
	std::cout << "[b:" << b << "]";
}

template <typename T>
void test_swap(T & a, T & b)
{
	::print_a_b(a, b);
	::swap(a, b);
	std::cout << COL_INFO_2 << "[swaping]";
	::print_a_b(a, b);
	std::cout << std::endl;
}

template <typename T>
void test_min(T & a, T & b)
{
	T	result;

	::print_a_b(a, b);
	result = ::min(a, b);
	std::cout << COL_INFO_2 << "[min:" << result << "]" << std::endl;
}

template <typename T>
void test_max(T & a, T & b)
{
	T	result;

	::print_a_b(a, b);
	result = ::max(a, b);
	std::cout << COL_INFO_2 << "[max:" << result << "]" << std::endl;
}

#endif // WHATEVER_H
