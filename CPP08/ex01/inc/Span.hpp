/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Span.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */
#include <limits>
/**
 * <template>	std::numeric_limits
 */
#include <cstdlib>
/**
 * <object>		abs
 */
#include <fstream>
/**
 * <object>		ifstream
 * <function>	is_open
 * <function>	open
 * <function>	close
 */
# include <exception>
/**
 * std::out_of_range()
 */
# include <list>

# ifndef DEBUG
#  define	DEBUG				0
# endif

# ifndef DEBUG_FD
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
# define	RST					ANSI_ESC "0m"

# define	H_CLASS				"[" G "CLASS" RST "] → "
# define	H_DEBUG				"[" B "DEBUG" RST "] → "
# define	H_ERROR				"[" R "ERROR" RST "] → "

void	debug(std::string msg);

class Span
{
	private:
		// VAR
		size_t	_len;
		std::list<int>	_list;

		// OTHER FUNCTION

	public:
		// CONSTRUCTOR
		Span(size_t);
		Span(const Span &copy);

		// DESTRUCTOR
		~Span(void);

		// OPERATOR
		Span	&operator=(const Span &src);

		// EXCEPTION

		// OTHER
		void	addNumber(int n);
		size_t	shortestSpan(void);
		size_t	longestSpan(void);
};

#endif // SPAN_CLASS
