/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Bureaucrat.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

# include "Form.hpp"

class Form;

# ifndef	DEBUG
#  define	DEBUG					1
# endif

# ifndef	DEBUG_FD
#  define	DEBUG_FD				420
# endif

# ifndef	VERBOSE
#  define	VERBOSE					1
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

# define	DEFAULT_GRADE			150

void	debug(std::string msg);

class Bureaucrat
{
	private:
		// VAR(S)
		const std::string	_name;
		int					_grade;

		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);

		// DESTRUCTOR(S)
		~Bureaucrat(void);

		// OPERATOR(S) FUNCTION
		Bureaucrat	&operator=(const Bureaucrat &src);
		Bureaucrat	&operator<<(const Bureaucrat &src);

		// GETTER(S)
		std::string	get_name(void) const;
		int			get_grade(void) const;

		// OTHER(S)
		void		inc_grade(void);
		void		dec_grade(void);
		void		sign_form(Form *to_sign);

		// EXCEPTION(S) CLASS
		class	EmptyNameException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out_stream, const Bureaucrat &src);

#endif // BUREAUCRAT_CLASS
