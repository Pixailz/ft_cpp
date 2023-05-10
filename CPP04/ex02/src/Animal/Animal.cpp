/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Animal.cpp                             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Animal.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	Animal::debug(std::string msg)
{
	if (DEBUG == 1)
	{
		std::cout << "(" << get_type() << ")";
		std::cout << "\x1b[" << MSG_POS << "G" << ": " << msg << std::endl;
	}
}

Animal::Animal(void) : _type("Animol")
{
	Animal::debug("Animal class created");
}

Animal::Animal(std::string type) : _type(type)
{
	Animal::debug("Animal class created (with string)");
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	Animal::debug("Animal class created (by copy)");
}

Animal::~Animal(void)
{
	Animal::debug("Animal class destructed");
}

Animal	&Animal::operator=(const Animal &src)
{
	this->set_type(src.get_type());
	Animal::debug("Animal operator '=' called");
	return (*this);
}

void Animal::set_type(std::string type)
{
	this->_type = type;
}

std::string Animal::get_type(void) const
{
	return (this->_type);
}

void	Animal::introduce(void) const
{
	std::cout << "(" << get_type() << ")";
	std::cout << "\x1b[" << MSG_POS << "G" << ": ";
}

void	Animal::makeSound(void) const
{
	introduce();
	std::cout << "**a little bit confused on what sound is should make**" << std::endl;
}
