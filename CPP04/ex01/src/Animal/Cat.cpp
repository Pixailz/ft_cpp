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
	Animal::debug("Cat class created");
}

Cat::~Cat(void)
{
	if (_my_brain)
		delete _my_brain;
	Animal::debug("Cat class destructed");
}

void	Cat::makeSound(void) const
{
	Animal::introduce();
	std::cout << "**MEOW**" << std::endl;
}
