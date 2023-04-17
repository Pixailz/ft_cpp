/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP02-ex01                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−03T19:51:24+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "Fixed.hpp"

int	main(void)
{
	std::cout << "default test" << std::endl;
	{
		Fixed	a;
		Fixed	const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	std::cout << std::endl << "basic arithmetic operator" << std::endl;
	{
		Fixed const a(1);
		Fixed const b(2);

		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
	}
	std::cout << std::endl << "logic operator" << std::endl;
	{
		Fixed const a(2);
		Fixed const b(2);

		std::cout << (a == b ? "A == B" : "A != B") << std::endl;
		std::cout << (a != b ? "A != B" : "A == B") << std::endl;
		std::cout << (a >= b ? "A >= B" : "A < B") << std::endl;
		std::cout << (a <= b ? "A <= B" : "A > B") << std::endl;
		std::cout << (a > b ? "A > B" : "A <= B") << std::endl;
		std::cout << (a < b ? "A < B" : "A >= B") << std::endl;
	}
	std::cout << std::endl << "post/pre fix operation" << std::endl;
	{
		Fixed	a(1);		// should be not const as it can be
							// directly modified

		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
	}
	std::cout << std::endl << "min / max test" << std::endl;
	{
		Fixed const a(5.7f);
		Fixed const b(5.8f);

		std::cout << "min " << Fixed::min(a, b) << std::endl;
		std::cout << "max " << Fixed::max(a, b) << std::endl;
	}
	return 0;
}
