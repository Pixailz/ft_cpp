/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Form.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

# include "Bureaucrat.hpp"

class Bureaucrat;

# ifndef DEBUG
#  define DEBUG					1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD				420
# endif

# ifndef VERBOSE
#  define VERBOSE				1
# endif

# define	ANSI_ESC				"\x1b["
# define	R						ANSI_ESC "38:2::192:0:0m"
# define	G						ANSI_ESC "38:2::0:192:0m"
# define	B						ANSI_ESC "38:2::0:64:192m"
# define	COL_INFO				ANSI_ESC "11G"
# define	RST						ANSI_ESC "0m"

# define	H_CLASS					"[" G "CLASS" RST "] → "
# define	H_DEBUG					"[" B "DEBUG" RST "] → "
# define	H_ERROR					"[" R "ERROR" RST "] → "

void	debug(std::string msg);

class Form
{
	private:
		// VAR(S)
		bool				_signed;
		const std::string	_name;
		const int			_sign_req_grade;
		const int			_exec_req_grade;

		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form &copy);

		// DESTRUCTOR(S)
		~Form(void);

		// OPERATOR(S) FUNCTION
		Form		&operator=(const Form &src);


		// GETTER(S)
		int			get_grade_sign(void) const;
		int			get_grade_exec(void) const;
		std::string	get_name(void) const;
		bool		get_is_signed(void) const;

		// OTHER(S)
		void		check_exception(void);
		void		be_signed(Bureaucrat signatory);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	EmptyNameException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	AlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out_stream, const Form &src);

#endif // FORM_CLASS
