/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		PmergeMeDeque.hpp                     | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef PMERGEMEDEQUE_HPP
# define PMERGEMEDEQUE_HPP

#include "main.h"
#include <deque>

class PmergeMeDeque
{
	private:
		// VAR
		std::deque<arrType>		_array;

		// OTHER FUNCTION
		PmergeMeDeque(void);
		PmergeMeDeque(const PmergeMeDeque &copy);
		PmergeMeDeque	&operator=(const PmergeMeDeque &src);

	public:
		// CONSTRUCTOR
		PmergeMeDeque(std::string array);

		// DESTRUCTOR
		~PmergeMeDeque(void);

		// OPERATOR

		// EXCEPTION

		// SETTER

		// GETTER
		std::deque<arrType>	get_array(void);

		// OTHER
		void					start_sorting(void);
		void					mergeSort(std::deque<arrType> &array);
		void					merge(
			std::deque<arrType> &left_array,
			std::deque<arrType> &right_array,
			std::deque<arrType> &array
		);
};

#endif // PMERGEMEDeque_CLASS
