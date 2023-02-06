
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

/*#BEGIN#_____________________>#_|DEPENDENCIES|_#<__________________________##*/

#include <iostream>
/**
 * <object>		std::cout
 * <object>		std::endl
 */

/*#END#_______________________<#_|DEPENDENCIES|_#>__________________________##*/

class Fixed
{
	private:
		// VAR(S)
		int					_raw_binary;
		static const int	_point_pos = 8;

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
		int		getRawBits_(void) const;

		// OTHER(S) FUNCTION
};

/*#BEGIN#________________________>#_|TYPEDEF|_#<____________________________##*/

/*#END#__________________________<#_|TYPEDEF|_#>____________________________##*/

/*#BEGIN#_____________________>#_|PROTOTYPE(S)|_#<__________________________##*/

/*#END#_______________________<#_|PROTOTYPE(S)|_#>__________________________##*/

#endif // FIXED_CLASS
