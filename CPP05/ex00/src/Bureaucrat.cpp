/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Bureaucrat.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Bureaucrat.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	this->_grade = 150;
	debug("Bureaucrat class created");
}

Bureaucrat::~Bureaucrat(void)
{
	debug("Bureaucrat class destructed");
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	debug("Bureaucrat class created (by copy)");
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	debug("Bureaucrat operator '=' called");
	return (*this);
}

std::string	Bureaucrat::get_name(void)
{
	return (this->_name);
}

int	Bureaucrat::get_grade(void)
{
	return (this->_grade);
}
