/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Animal_a.cpp                           | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Animal_a.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	Animal_a::debug(std::string msg)
{
	if (DEBUG == 1)
	{
		std::cout << "(" << get_type() << ")";
		std::cout << "\x1b[" << MSG_POS << "G" << ": " << msg << std::endl;
	}
}

Animal_a::Animal_a(void) : _type("Animol")
{
	Animal_a::debug("Animal_a class created");
}

Animal_a::Animal_a(std::string type) : _type(type)
{
	Animal_a::debug("Animal_a class created (with string)");
}

Animal_a::Animal_a(const Animal_a &copy)
{
	*this = copy;
	Animal_a::debug("Animal_a class created (by copy)");
}

Animal_a::~Animal_a(void)
{
	Animal_a::debug("Animal_a class destructed");
}

Animal_a	&Animal_a::operator=(const Animal_a &src)
{
	_type = src.get_type();
	Animal_a::debug("Animal_a operator '=' called");
	return (*this);
}

void Animal_a::set_type(std::string type)
{
	this->_type = type;
}

std::string Animal_a::get_type(void) const
{
	return (this->_type);
}

void	Animal_a::introduce(void) const
{
	std::cout << "(" << get_type() << ")";
	std::cout << "\x1b[" << MSG_POS << "G" << ": ";
}

void	Animal_a::makeSound(void) const
{
	introduce();
	std::cout << "**a little bit confused on what sound is should make**" << std::endl;
}
