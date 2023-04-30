/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		WrongAnimal_a.cpp                        | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <WrongAnimal_a.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	WrongAnimal_a::debug(std::string msg)
{
	if (DEBUG == 1)
	{
		std::cout << "(" << get_type() << ")";
		std::cout << "\x1b[" << MSG_POS << "G" << ": " << msg << std::endl;
	}
}

WrongAnimal_a::WrongAnimal_a(void) : _type("WrongAnimol")
{
	WrongAnimal_a::debug("WrongAnimal_a class created");
}

WrongAnimal_a::WrongAnimal_a(std::string type) : _type(type)
{
	WrongAnimal_a::debug("WrongAnimal_a class created (with string)");
}

WrongAnimal_a::WrongAnimal_a(const WrongAnimal_a &copy)
{
	*this = copy;
	WrongAnimal_a::debug("WrongAnimal_a class created (by copy)");
}

WrongAnimal_a::~WrongAnimal_a(void)
{
	WrongAnimal_a::debug("WrongAnimal_a class destructed");
}

WrongAnimal_a	&WrongAnimal_a::operator=(const WrongAnimal_a &src)
{
	_type = src.get_type();
	WrongAnimal_a::debug("WrongAnimal_a operator '=' called");
	return (*this);
}

void WrongAnimal_a::set_type(std::string type)
{
	this->_type = type;
}

std::string WrongAnimal_a::get_type(void) const
{
	return (this->_type);
}

void	WrongAnimal_a::introduce(void) const
{
	std::cout << "(" << get_type() << ")";
	std::cout << "\x1b[" << MSG_POS << "G" << ": ";
}

void	WrongAnimal_a::makeSound(void) const
{
	introduce();
	std::cout << "**a little bit confused on what sound is should make**" << std::endl;
}
