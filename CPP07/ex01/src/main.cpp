/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−06−18T05:56:28+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include <iter.h>

template <class myType>
void print(myType &p){
	std::cout << p << std::endl;
}

template <class myType>
void addone(myType &nb){
	nb++;
}

int main(void){
	int numbers[] = {1, 2, 3, 4, 5};
	iter(numbers, 5, addone);
	iter(numbers, 5, print);

	std::string words[] = {"Hello", "Hi", "good", "bye"};
	iter(words, 4, print);
	return (0);
}
