
/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Fixed.hpp                              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP02-ex00                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

class Fixed
{
	private:
		// VAR(S)
		int					_raw_binary;
		static const int	_binary_point_pos = 8;

		// OTHER(S) FUNCTION

	public:
		// CONSTRUCTOR(S)
		Fixed(void);
		Fixed(const Fixed &copy);

		// DESTRUCTOR(S)
		~Fixed(void);

		// OPERATOR(S)
		Fixed	&operator=(const Fixed &src);

		// SETTER(S) FUNCTION
		void	setRawBits(const int raw);

		// GETTER(S) FUNCTION
		int		getRawBits(void) const;

		// OTHER(S) FUNCTION
};

#endif // FIXED_CLASS
