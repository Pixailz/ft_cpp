/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		WrongAnimal.cpp                        | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <WrongAnimal.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	WrongAnimal::debug(std::string msg)
{
	if (DEBUG == 1)
	{
		std::cout << "(" << get_type() << ")";
		std::cout << "\x1b[" << MSG_POS << "G" << ": " << msg << std::endl;
	}
}

WrongAnimal::WrongAnimal(void) : _type("WrongAnimol")
{
	WrongAnimal::debug("WrongAnimal class created");
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	WrongAnimal::debug("WrongAnimal class created (with string)");
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	WrongAnimal::debug("WrongAnimal class created (by copy)");
}

WrongAnimal::~WrongAnimal(void)
{
	WrongAnimal::debug("WrongAnimal class destructed");
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	this->set_type(src.get_type());
	WrongAnimal::debug("WrongAnimal operator '=' called");
	return (*this);
}

void WrongAnimal::set_type(std::string type)
{
	this->_type = type;
}

std::string WrongAnimal::get_type(void) const
{
	return (this->_type);
}

void	WrongAnimal::introduce(void) const
{
	std::cout << "(" << get_type() << ")";
	std::cout << "\x1b[" << MSG_POS << "G" << ": ";
}

void	WrongAnimal::makeSound(void) const
{
	introduce();
	std::cout << "**a little bit confused on what sound is should make**" << std::endl;
}
