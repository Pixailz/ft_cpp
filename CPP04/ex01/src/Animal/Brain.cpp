/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Brain.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Brain.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

Brain::Brain(void)
{
	debug("Brain class created");
}

Brain::~Brain(void)
{
	debug("Brain class destructed");
}

Brain::Brain(const Brain &copy)
{
	debug("Brain class created (by copy)");
	*this = copy;
}

void	Brain::say_ideas(void)
{
	for (int i = 0; i< NB_IDEAS; i++)
		std::cout << "ideas[" << i << "] : {" << this->_ideas[i] << "}" << std::endl;
}

Brain	&Brain::operator=(const Brain &src)
{
	debug("Brain operator '=' called");
	for (int i = 0; i < NB_IDEAS; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}
