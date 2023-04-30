/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Cat.hpp                                | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef CAT_HPP
# define CAT_HPP

# include <Animal_a.hpp>
# include <Brain.hpp>

class Cat : public Animal_a
{
	private:
		// VAR(S)
		Brain		*_my_brain;
		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		Cat(void);

		void	makeSound(void) const;
};

#endif // DOG_CLASS
