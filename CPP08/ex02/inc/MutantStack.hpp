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

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

# include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */
#include <string>
# include <stack>

# ifndef DEBUG
#  define	DEBUG				1
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

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack( MutantStack const & src )
		{
			*this = src;
		};
		virtual ~MutantStack() {};
		MutantStack<T> &operator=( MutantStack<T> const & copy )
		{
			if (*this != copy)
				*this = copy;
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator				begin() {
			return this->c.begin();
		};
		iterator				end() {
			return this->c.end();
		};
		const_iterator			cbegin() const {
			return this->c.cbegin();
		};
		const_iterator			cend() const {
			return this->c.cend();
		};
		reverse_iterator		rbegin() {
			return this->c.rbegin();
		};
		reverse_iterator		rend() {
			return this->c.rend();
		};
		const_reverse_iterator	crbegin() const {
			return this->c.crbegin();
		};
		const_reverse_iterator	crend() const {
			return this->c.crend();
		};
	private:
};

#endif // MUTANT_STACK_HPP
