
/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Fixed.hpp                              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP02-ex02                             |  __/| \ \/ /   ##*/
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

# define DEBUG						0
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

		// SETTER(S) FUNCTION
		void		setRawBits(const int raw_value);

		// GETTER(S) FUNCTION
		int			getRawBits(void) const;

		// OPERATOR(S)
		Fixed				&operator=(const Fixed &src);
		/* LOGIC OPERATOR
		BASE				(A>B)
		COMPOSITE			==: !(A>B) && !(B>A)
							>=:	A>B || A==B
							<:	!(A>B) && !(A==B)
							<=:	!(A>B)
							!=:	!(A==B)
		*/
		bool				operator>(const Fixed &B) const;
		bool				operator==(const Fixed &B) const;
		bool				operator!=(const Fixed &B) const;
		bool				operator>=(const Fixed &B) const;
		bool				operator<(const Fixed &B) const;
		bool				operator<=(const Fixed &B) const;
		// ARITHMETIC OPERATOR
		Fixed				operator+(const Fixed &B) const;
		Fixed				operator-(const Fixed &B) const;
		Fixed				operator*(const Fixed &B) const;
		Fixed				operator/(const Fixed &B) const;
		// INCREMENT / DECREMENT
		Fixed				&operator++(void);	// prefix
		Fixed				operator++(int);	// postfix
		Fixed				&operator--(void);	// prefix
		Fixed				operator--(int);	// postfix

		// OTHER(S) FUNCTION
		int					toInt(void) const;
		float				toFloat(void) const;
		static Fixed		&min(Fixed &lhs, Fixed &rhs);
		static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed		&max(Fixed &lhs, Fixed &rhs);
		static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);
};

std::ostream	&operator<<(std::ostream &out_stream, const Fixed &src);

#endif // FIXED_CLASS
