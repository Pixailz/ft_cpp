/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		PmergeMeVector.hpp                     | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef PMERGEMEVECTOR_HPP
# define PMERGEMEVECTOR_HPP

#include "main.h"
#include <vector>

class PmergeMeVector
{
	private:
		// VAR
		std::vector<arrType>		_array;

		// OTHER FUNCTION
		PmergeMeVector(void);
		PmergeMeVector(const PmergeMeVector &copy);
		PmergeMeVector	&operator=(const PmergeMeVector &src);

	public:
		// CONSTRUCTOR
		PmergeMeVector(std::string array);

		// DESTRUCTOR
		~PmergeMeVector(void);

		// OPERATOR

		// EXCEPTION

		// SETTER

		// GETTER
		std::vector<arrType>	get_array(void);

		// OTHER
		void					start_sorting(void);
		void					mergeSort(std::vector<arrType> &array);
		void					merge(
			std::vector<arrType> &left_array,
			std::vector<arrType> &right_array,
			std::vector<arrType> &array
		);
};

#endif // PMERGEMEVECTOR_CLASS
