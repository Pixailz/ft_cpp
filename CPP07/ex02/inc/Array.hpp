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
/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

# include <iostream>
/**
 * <object>		std::cout
 * <object>		std::cerr
 * <object>		std::endl
 */

# ifndef DEBUG
#  define	DEBUG					1
# endif

# ifndef DEBUG_FD
#  define	DEBUG_FD				420
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

typedef unsigned int t_size;

template <typename T>
class Array
{
	private:
		t_size	_len;
		T		*_content;

	public:
		Array(void) : _len(0), _content(NULL)
		{};

		Array(t_size len) : _len(len)
		{
			this->_content = new T[len];
		};

		Array(const Array &src) : _content(NULL)
		{
			*this = src;
		};

		~Array(void)
		{
			if (!this->_content)
				return ;
			delete [] this->_content;
		};

		Array &operator=(const Array &src)
		{
			t_size len = src.size();

			if (this->_content)
				delete [] this->_content;
			this->_content = new T [len];
			this->_len = len;
			for (t_size i = 0; i < len; i++)
				this->_content[i] = src._content[i];
			return (*this);
		};

		t_size size(void) const
		{
			return (this->_len);
		};

		T &operator[](int index)
		{
			if (index < 0)
				throw Array::OutOfBound();
			if (!this->_len)
				throw Array::OutOfBound();
			if (static_cast<t_size>(index) > this->_len - 1)
				throw Array::OutOfBound();
			return (this->_content[index]);
		}

		class OutOfBound: public std::exception
		{
			virtual const char*	what() const throw()
			{
				return (H_ERROR "Out of bound");
			}
		};
};

#endif // MAIN_H
