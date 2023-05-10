/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		WrongCat.cpp                           | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <WrongCat.hpp>
/**
 * <object>		object
 * <function>	function()
 */

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	_my_brain = new Brain();
	WrongCat::debug("WrongCat class created");
}

WrongCat::~WrongCat(void)
{
	WrongCat::debug("WrongCat class destructed");
	delete this->_my_brain;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	*this = copy;
	WrongCat::debug("WrongCat class created (by copy)");
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	this->set_type(src.get_type());
	this->_my_brain = new Brain(*src._my_brain);
	WrongCat::debug("WrongCat operator '=' called");
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	WrongCat::introduce();
	std::cout << "**MEOW**" << std::endl;
}
