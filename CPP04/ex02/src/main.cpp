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

// SAME EXEMPLE AS ex01, but idk why i have nothing to change to make it work
int	main(void)
{
	{		// BASE EXEMPLE
		const Animal_a* j = new Dog();
		const Animal_a* i = new Cat();

		delete j;
		delete i;
	}
	{		// WRONG BASE EXEMPLE
		const WrongAnimal_a* j = new WrongCat();

		delete j;
	}
	{		// check if really no leaks
		const Animal_a* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

		for ( int i = 0; i < 4; i++ )
		{
			animals[i]->makeSound();
			delete animals[i];
		}
	}
	{
		// SHOULD NOT WORK
		// const Animal_a *j = new Animal();
		// delete j;
	}
	return (0);
}
