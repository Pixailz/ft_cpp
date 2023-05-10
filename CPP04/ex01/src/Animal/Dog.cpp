/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Dog.cpp                                | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Dog.hpp>
/**
 * <object>		object
 * <function>	function()
 */

Dog::Dog(void) : Animal("Dog")
{
	_my_brain = new Brain();
	Dog::debug("Dog class created");
}

Dog::~Dog(void)
{
	Dog::debug("Dog class destructed");
	delete this->_my_brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;
	Dog::debug("Dog class created (by copy)");
}

Dog	&Dog::operator=(const Dog &src)
{
	this->set_type(src.get_type());
	this->_my_brain = new Brain(*src._my_brain);
	Dog::debug("Dog operator '=' called");
	return (*this);
}

void	Dog::makeSound(void) const
{
	Dog::introduce();
	std::cout << "**WOUF**" << std::endl;
}
