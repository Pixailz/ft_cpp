/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Fixed.cpp                              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP02-ex01                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include "Fixed.hpp"

Fixed::Fixed(void) : _raw_binary(0)
{
	std::cout << "Fixed class created (default)" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Fixed class created (by copy)" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int raw_value)
{
	_raw_binary = raw_value << _binary_point_pos;
	std::cout << "Fixed class created (with int)" << std::endl;
}

Fixed::Fixed(const float raw_value)
{
	_raw_binary = roundf(raw_value * (1 << _binary_point_pos));
	std::cout << "Fixed class created (with float)" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed class destructed" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	_raw_binary = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return (_raw_binary);
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Fixed operator '=' called" << std::endl;
	if (this != &src)
		_raw_binary = src.getRawBits();
	return *this;
}

Fixed	&Fixed::operator<=(const Fixed &src)
{
	std::cout << "Fixed operator '<=' called" << std::endl;
	if (this != &src)
		_raw_binary = src.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &out_stream, const Fixed &src)
{
	out_stream << src.toFloat();
	return (out_stream);
}

int	Fixed::toInt(void) const
{
	return (_raw_binary >> _binary_point_pos);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _binary_point_pos));
}
