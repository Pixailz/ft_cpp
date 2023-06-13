/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ShruberryCreationForm.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
/**
 * <object>		ofstream
 * <function>	open
 * <function>	close
 */
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

class ShruberryCreationForm : public AForm
{
	private:
		// VAR(S)
		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		ShruberryCreationForm(std::string target);
		ShruberryCreationForm(const ShruberryCreationForm &copy);

		// DESTRUCTOR(S)
		~ShruberryCreationForm(void);

		// OPERATOR(S) FUNCTION
		ShruberryCreationForm	&operator=(const ShruberryCreationForm &src);

		void					execute_specific(Bureaucrat const & executor);
};

#endif // SHRUBERRYCREATIONFORM_CLASS
