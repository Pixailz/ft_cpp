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

#include <deque>

typedef std::deque<arrType>	deq;
typedef std::deque<deq>		deqDeq;

typedef deq::iterator			deqIt;
typedef deqDeq::iterator		deqDeqIt;

class PmergeMeDeque
{
	private:
		// VAR
		deq			_array;
		size_t		_array_len;

		bool		_has_odd;
		arrType		_odd;

		deqDeq		_pair_array;
		// vecVec		_sorted_pair_array;

		// OTHER FUNCTION
		PmergeMeDeque(void);
		PmergeMeDeque(const PmergeMeDeque &copy);
		PmergeMeDeque	&operator=(const PmergeMeDeque &src);

		void					create_pair(void);
		void					compare_pair(void);
		void					sort_pair(void);
		void					mergeSort(deqDeq &array);
		void					merge(
			deqDeq &left_array,
			deqDeq &right_array,
			deqDeq &array
		);
		void					mergeInsert(void);

	public:
		// CONSTRUCTOR
		PmergeMeDeque(char **av);

		// DESTRUCTOR
		~PmergeMeDeque(void);

		// OPERATOR

		// EXCEPTION

		// SETTER

		// GETTER
		deq	get_array(void);

		// OTHER
		void					start_sorting(void);
};

#endif // PMERGEMEVECTOR_CLASS
