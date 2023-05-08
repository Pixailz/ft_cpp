/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		WrongCat.hpp                           | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <WrongAnimal.hpp>
# include <Brain.hpp>

class WrongCat : public WrongAnimal
{
	private:
		// VAR(S)
		Brain		*_my_brain;

		// OTHER(S) FUNCTION

	public:
		virtual	~WrongCat(void);
		// CONSTRUCTOR(S)
		WrongCat(void);

		void	makeSound(void) const;
};

#endif // DOG_CLASS
