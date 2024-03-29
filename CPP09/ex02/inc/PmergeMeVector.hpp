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

#include <vector>

typedef std::vector<arrType>	vec;
typedef std::vector<vec>		vecVec;

typedef vec::iterator			vecIt;
typedef vecVec::iterator		vecVecIt;

class PmergeMeVector
{
	private:
		// VAR
		vec			_array;
		size_t		_array_len;

		bool		_has_odd;
		arrType		_odd;

		vecVec		_pair_array;
		// vecVec		_sorted_pair_array;

		// OTHER FUNCTION
		PmergeMeVector(void);
		PmergeMeVector(const PmergeMeVector &copy);
		PmergeMeVector	&operator=(const PmergeMeVector &src);

		void					create_pair(void);
		void					compare_pair(void);
		void					sort_pair(void);
		void					mergeSort(vecVec &array);
		void					merge(
			vecVec &left_array,
			vecVec &right_array,
			vecVec &array
		);
		void					mergeInsert(void);

	public:
		// CONSTRUCTOR
		PmergeMeVector(char **av);

		// DESTRUCTOR
		~PmergeMeVector(void);

		// OPERATOR

		// EXCEPTION

		// SETTER

		// GETTER
		vec	get_array(void);

		// OTHER
		void					start_sorting(void);
};

#endif // PMERGEMEVECTOR_CLASS
