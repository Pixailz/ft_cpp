/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Cat.cpp                                | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Cat.hpp>
/**
 * <object>		object
 * <function>	function()
 */

Cat::Cat(void) : Animal("Cat")
{
	_my_brain = new Brain();
	Cat::debug("Cat class created");
}

Cat::~Cat(void)
{
	Cat::debug("Cat class destructed");
	delete this->_my_brain;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	*this = copy;
	Cat::debug("Cat class created (by copy)");
}

Cat	&Cat::operator=(const Cat &src)
{
	this->set_type(src.get_type());
	this->_my_brain = new Brain(*src._my_brain);
	Cat::debug("Cat operator '=' called");
	return (*this);
}

void	Cat::makeSound(void) const
{
	Cat::introduce();
	std::cout << "**MEOW**" << std::endl;
}
