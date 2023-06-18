/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.h                               | |_/ /___  __   ##*/
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

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */
#include <cstring>
/**
 * <function >	strchr
 */

#include <sstream>
/**
 * <object>		std::hex
 * <object>		std::stringstream
 */
#include <iomanip>
/**
 * <function>	std::setfill
 * <function>	std::setw
 */
#include <limits>
/**
 * <template>	std::numeric_limits
 */
#include <math.h>
/**
 * <function>	nanf
 * <function>	+inff
 * <function>	-inff
 * <function>	nan
 * <function>	+inf
 * <function>	-inf
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
# define	RST					ANSI_ESC "0m"

# define	H_SEP				" → "

# define	H_CLASS				"[" G "CLASS" RST "]" H_SEP
# define	H_DEBUG				"[" B "DEBUG" RST "]" H_SEP
# define	H_ERROR				"[" R "ERROR" RST "]" H_SEP

# define	H_CHAR				"[" G "CHAR " RST "]" H_SEP
# define	H_INT				"[" G "INT  " RST "]" H_SEP
# define	H_FLOAT				"[" G "FLOAT" RST "]" H_SEP
# define	H_DOUBLE			"[" G "DOUBL" RST "]" H_SEP
# define	H_UNKNOWN			"[" R "UNKNO" RST "]" H_SEP

typedef unsigned char	t_uint8;

void	debug(std::string msg);

#endif // MAIN_H
