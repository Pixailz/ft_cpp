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

# ifndef DEBUG
#  define DEBUG					1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD				420
# endif

# ifndef VERBOSE
#  define VERBOSE				1
# endif

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
		Bureaucrat(const Bureaucrat &copy);

		// DESTRUCTOR(S)
		~Bureaucrat(void);

		// OPERATOR(S) FUNCTION
		Bureaucrat	&operator=(const Bureaucrat &src);

		// GETTER(S)
		std::string	get_name(void);
		int			get_grade(void);
};

#endif // BUREAUCRAT_CLASS
