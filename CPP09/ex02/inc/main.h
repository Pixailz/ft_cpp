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

#ifndef MAIN_H
# define MAIN_H
/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

# include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */
#include <cstdlib>
/**
 * <function>	std::atoi()
 */
#include <sys/time.h>
/**
 * <function>	gettimeofday()
 * <object>		timeval
 */
#include <iomanip>
#include <limits>

#include <vector>
#include <deque>
#include <sstream>

# ifndef DEBUG
#  define	DEBUG				1
# endif

# ifndef DEBUG_FD
#  define	DEBUG_FD			420
# endif

# ifndef	VERBOSE
#  define	VERBOSE				1
# endif

# define	MAX_DISPLAY_N		15;

# define	ANSI_ESC			"\x1b["
# define	R					ANSI_ESC "38:2::192:0:0m"
# define	G					ANSI_ESC "38:2::0:192:0m"
# define	B					ANSI_ESC "38:2::0:64:192m"
# define	COL_INFO			ANSI_ESC "11G"
# define	RST					ANSI_ESC "0m"
# define	COL_ARRAY			ANSI_ESC "35G"

# define	H_CLASS				"[" G "CLASS" RST "] → "
# define	H_DEBUG				"[" B "DEBUG" RST "] "
# define	H_INFO				"[" G "INFO " RST "] "
# define	H_ERROR				"[" R "ERROR" RST "] → "

# define	MICRO_SEC_STR		"μs"

typedef int		arrType;

#include "PmergeMeVector.hpp"
#include "PmergeMeDeque.hpp"

typedef double	ts;

void	debug(std::string msg);

void	err(std::string msg);
void	err(std::string title, std::string msg);
bool	is_good_number(char n);

void	print_vec_t(std::string title, vec array);
void	print_deq_t(std::string title, deq array);

void	print_vec_vec(vecVec array);

int		parse_number(std::string n);

void	display_elapsed_time_usec(std::string title, timeval begin, timeval end);

bool	is_arr_sorted(vecVec array);

std::string	to_string(int value);

class	ParsingError: public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif // MAIN_H
