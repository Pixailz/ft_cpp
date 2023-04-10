
/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Fixed.hpp                              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP02-ex01                             |  __/| \ \/ /   ##*/
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
 * <object>		std::ostream
 */

#include <cmath>
/**
 * <function>	roundf()
 */

# define FIXED_POINT_LEN			16

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
		Fixed(const int raw_value);
		Fixed(const float raw_value);

		// DESTRUCTOR(S)
		~Fixed(void);

		// OPERATOR(S)
		Fixed	&operator=(const Fixed &src);
		Fixed	&operator>=(const Fixed &Fixed1, const Fixed &Fixed2);

		// SETTER(S) FUNCTION
		void	setRawBits(const int raw_value);

		// GETTER(S) FUNCTION
		int		getRawBits(void) const;

		// OTHER(S) FUNCTION
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &out_stream, const Fixed &src);

#endif // FIXED_CLASS
