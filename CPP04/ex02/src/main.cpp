/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−04−18T00:20:29+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongCat.hpp>

int	main(void)
{
	{
		Cat cat_basic;
		{
			Cat tmp = cat_basic;
		}
		Dog dog_basic;
		{
			Dog tmp = dog_basic;
		}
	}
		{		// BASE EXEMPLE
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}
	{		// WRONG BASE EXEMPLE
		const WrongAnimal* j = new WrongCat();

		delete j;
	}
	{		// check if really no leaks
		const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

		for ( int i = 0; i < 4; i++ )
		{
			animals[i]->makeSound();
			delete animals[i];
		}
	}
	{// should not work
		// Animal error_1 = Animal();
	}
	return (0);
}
