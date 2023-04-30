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
	{	// BASE TEST
		Animal	abo_01;
		Dog		doggy_01;
		Cat		cat_01;

		std::cout << abo_01.get_type() << std::endl;
		std::cout << doggy_01.get_type() << std::endl;
		std::cout << cat_01.get_type() << std::endl;

		abo_01.makeSound();
		doggy_01.makeSound();
		cat_01.makeSound();
	}
	{
		Dog		dog_01;
		Dog		dog_02(dog_01);		// dog herite des constructeur de Animal
		Cat		cat_01;
		Animal	abo_01;
		Animal	abo_02;
		Animal	abo_03(cat_01);

		abo_01 = dog_02;			// Animal = Dog : 1
		abo_01 = cat_01;			// Animal = Cat : 1
		//cat_01 = dog_02;			// Cat = Dog : 0
		std::cout << "dog_01 ";
		dog_01.makeSound();
		std::cout << "dog_02 ";
		dog_02.makeSound();
		std::cout << "cat_01 ";
		cat_01.makeSound();
		std::cout << "abo_01 ";
		abo_01.makeSound();
		std::cout << "abo_02 ";
		abo_02.makeSound();
		std::cout << "abo_03 ";
		abo_03.makeSound();
	}
	{	// EXEMPLE TEST
		const Animal *meta = new Animal();
		const Animal * j = new Dog();
		const Animal * i = new Cat();

		std::cout << meta->get_type() << std::endl;
		std::cout << j->get_type() << std::endl;
		std::cout << i->get_type() << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{	// EXEMPLE TEST WITH WRONGANIMAL CLASS
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal * j = new WrongCat();

		std::cout << meta->get_type() << std::endl;
		std::cout << j->get_type() << std::endl;
		meta->makeSound();
		j->makeSound();

		delete meta;
		delete j;
	}
	return (0);
}
