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
	WrongAnimal::debug("WrongCat class created");
}

void	WrongCat::makeSound(void) const
{
	WrongAnimal::introduce();
	std::cout << "**WRONGMEOW**" << std::endl;
}
