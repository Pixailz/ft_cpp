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
	Animal::debug("Dog class created");
}

Dog::~Dog(void)
{
	if (_my_brain)
		delete _my_brain;
	Animal::debug("Dog class destructed");
}

void	Dog::makeSound(void) const
{
	Animal::introduce();
	std::cout << "**WOUF**" << std::endl;
}
