/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Intern.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
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

void	debug(std::string msg);

typedef struct s_typeForm
{
	std::string	name;
	AForm		*(*func)(std::string const &taget);
}				t_typeForm;

class Intern
{
	private:
		// VAR(S)
		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		Intern(void);
		Intern(const Intern &copy);

		// DESTRUCTOR(S)
		~Intern(void);

		// OPERATOR(S) FUNCTION
		Intern	&operator=(const Intern &src);

		AForm*	make_form(std::string name, std::string target);

		class	CannotCreatForm : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return (H_ERROR "Intern cannot create not found form");
				}
		};
};

#endif // INTERN_CLASS
