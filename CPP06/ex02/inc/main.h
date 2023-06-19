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

# include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */
#include <fstream>
/**
 * <object>		ifstream
 * <function>	is_open
 * <function>	open
 * <function>	close
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
# define	RE					ANSI_ESC "38:2::192:0:0m"
# define	GR					ANSI_ESC "38:2::0:192:0m"
# define	BL					ANSI_ESC "38:2::0:64:192m"
# define	OR					ANSI_ESC "38;5;214m"
# define	COL_INFO			ANSI_ESC "11G"
# define	RST					ANSI_ESC "0m"

# define	H_SEP				" → "

# define	H_CLASS				"[" GR "CLASS" RST "]" H_SEP
# define	H_DEBUG				"[" BL "DEBUG" RST "]" H_SEP
# define	H_ERROR				"[" RE "ERROR" RST "]" H_SEP

# define	H_A					"[" BL "A" RST "]"
# define	H_B					"[" GR "B" RST "]"
# define	H_C					"[" RE "C" RST "]"
# define	H_U					"[" OR "?" RST "]"

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

#endif // MAIN_H
