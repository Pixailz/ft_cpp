/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ScalarConverter.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <ScalarConverter.hpp>

// Constructor (void)
ScalarConverter::ScalarConverter(void)
{
	debug("ScalarConverter class created");
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
	debug("ScalarConverter class destructed");
}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	debug("ScalarConverter class created (by copy)");
	*this = copy;
}

// '=' operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	debug("ScalarConverter operator '=' called");
	return (*this);
}

// Exception
const char*	ScalarConverter::EmptyInputErr::what() const throw()
{
	return (H_ERROR "Input cannot be empty" H_SEP);
}

const char*	ScalarConverter::UnknownTypeConversionErr::what() const throw()
{
	return (H_ERROR "Impossible convertion, unknown type" H_SEP);
}

// Other
void	ScalarConverter::convert(std::string in)
{
	try {
		t_type	type = ScalarConverter::get_type(in);
		std::cout << ScalarConverter::get_type_str(type)
				  << "[" << in << "]" << std::endl;
		switch (type)
		{
			case CHAR:		ScalarConverter::convert_char(in);		break;
			case INT:		ScalarConverter::convert_int(in);		break;
			case FLOAT:		ScalarConverter::convert_float(in);		break;
			case DOUBLE:	ScalarConverter::convert_double(in);	break;
			default:		throw ScalarConverter::UnknownTypeConversionErr();
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << in << std::endl;
	}
}

t_type	ScalarConverter::get_type(std::string in)
{
	if (!in.length())
		throw ScalarConverter::EmptyInputErr();
	if (ScalarConverter::is_char(in))
		return (CHAR);
	else if (ScalarConverter::is_int(in))
		return (INT);
	else if (ScalarConverter::is_float(in))
		return (FLOAT);
	else if (ScalarConverter::is_decimal(in))
		return (DOUBLE);
	else if (in == "-inff" || in == "+inff" || in == "nanf")
		return (FLOAT);
	else if (in == "-inf" || in == "+inf" || in == "nan")
		return (DOUBLE);
	return (UNKNOWN);
}

std::string	ScalarConverter::get_type_str(t_type type)
{
	switch (type) {
		case CHAR:		return (H_CHAR);
		case INT:		return (H_INT);
		case FLOAT:		return (H_FLOAT);
		case DOUBLE:	return (H_DOUBLE);
		default:		return (H_UNKNOWN);
	}
}

bool	ScalarConverter::is_char(std::string in)
{
	if (in.length() != 3)
		return (false);
	if (in[0] == '"' && in[2] == '"')
		return (true);
	if (in[0] == '\'' && in[2] == '\'')
		return (true);
	return (false);
}

bool	ScalarConverter::is_int(std::string in)
{
	int			index = 0;

	if (in[index] == '+' || in[index] == '-')
		index++;
	while (in[index])
		if (in[index] < '0' || in[index++] > '9')
			return (false);
	return (true);
}

bool	ScalarConverter::is_float(std::string in)
{
	if (in[in.length() - 1] != 'f' && in[in.length() - 1] != 'F')
		return (false);
	in[in.length() - 1] = 0;
	return (ScalarConverter::is_decimal(in));
}

bool	ScalarConverter::is_decimal(std::string in)
{
	int			index = 0;
	bool		have_dot = false;

	if (in[index] == '+' || in[index] == '-')
		index++;
	index--;
	while (in[++index])
	{
		if (in[index] == '.')
		{
			if (have_dot == true)
				return (false);
			have_dot = true;
			continue;
		}
		if (in[index] >= '0' && in[index] <= '9')
			continue;
		return (false);
	}
	return (true);
}

void	ScalarConverter::convert_char(std::string in)
{
	short	out = static_cast<char>(in[1]);
	bool	is_convertible = false;

	if (out <= std::numeric_limits<char>::max()
	&&	out >= std::numeric_limits<char>::min())
		is_convertible = true;
	ScalarConverter::print_char(out, is_convertible);
	ScalarConverter::print_int(static_cast<int>(out), is_convertible);
	ScalarConverter::print_float(static_cast<float>(out), is_convertible);
	ScalarConverter::print_double(static_cast<double>(out), is_convertible);
}

void	ScalarConverter::convert_int(std::string in)
{
	long int	out;
	bool		is_convertible = false;
	bool		is_convertible_char = false;
	std::stringstream(in) >> out;

	if (out <= std::numeric_limits<int>::max()
	&&	out >= std::numeric_limits<int>::min())
		is_convertible = true;
	if (is_convertible && out <= std::numeric_limits<char>::max()
	&&	out >= std::numeric_limits<char>::min())
		is_convertible_char = true;
	ScalarConverter::print_char(static_cast<char>(out), is_convertible_char);
	ScalarConverter::print_int(static_cast<int>(out), is_convertible);
	ScalarConverter::print_float(static_cast<float>(out), is_convertible);
	ScalarConverter::print_double(static_cast<double>(out), is_convertible);
}

void	ScalarConverter::convert_float(std::string in)
{
	if (in == "nanf" || in == "+inff" || in == "-inff")
	{
		ScalarConverter::print_char(0, false);
		ScalarConverter::print_int(0, false);
		ScalarConverter::print_float(in);
		in[3] = 0;
		ScalarConverter::print_double(in);
	}
	else
	{
		double	out;
		std::stringstream(in) >> out;

		if (out <= std::numeric_limits<char>::max()
		&&	out >= std::numeric_limits<char>::min())
			ScalarConverter::print_char(static_cast<char>(out), true);
		else
			ScalarConverter::print_char(static_cast<char>(out), false);
		if (out <= std::numeric_limits<int>::max()
		&&	out >= -std::numeric_limits<int>::max())
			ScalarConverter::print_int(static_cast<int>(out), true);
		else
			ScalarConverter::print_int(static_cast<int>(out), false);
		if (out <= std::numeric_limits<float>::max()
		&&	out >= -std::numeric_limits<float>::max())
		{
			ScalarConverter::print_float(static_cast<float>(out), true);
			ScalarConverter::print_double(static_cast<double>(out), true);
		}
		else
		{
			ScalarConverter::print_float(static_cast<float>(out), false);
			ScalarConverter::print_double(static_cast<double>(out), false);
		}
	}
}

void	ScalarConverter::convert_double(std::string in)
{
	if (in == "nan" || in == "+inf" || in == "-inf")
	{
		ScalarConverter::print_char(0, false);
		ScalarConverter::print_int(0, false);
		ScalarConverter::print_float(in + "f");
		ScalarConverter::print_double(in);
	}
	else
	{
		long double	out;
		std::stringstream(in) >> out;

		if (out <= std::numeric_limits<char>::max()
		&&	out >= std::numeric_limits<char>::min())
			ScalarConverter::print_char(static_cast<char>(out), true);
		else
			ScalarConverter::print_char(static_cast<char>(out), false);
		if (out <= std::numeric_limits<int>::max()
		&&	out >= std::numeric_limits<int>::min())
			ScalarConverter::print_int(static_cast<int>(out), true);
		else
			ScalarConverter::print_int(static_cast<int>(out), false);
		if (out <= std::numeric_limits<float>::max()
		&&	out >= -std::numeric_limits<float>::max())
			ScalarConverter::print_float(static_cast<float>(out), true);
		else
			ScalarConverter::print_float(static_cast<float>(out), false);
		if (out <= std::numeric_limits<double>::max()
		&&	out >= -std::numeric_limits<double>::max())
			ScalarConverter::print_double(static_cast<double>(out), true);
		else
			ScalarConverter::print_double(static_cast<double>(out), false);
	}
}

void	ScalarConverter::print_char(char c, bool possible)
{
	std::cout << "Char   " << H_SEP;
	if (possible)
	{
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << ScalarConverter::convert_hex(c) << " (Non displayable)" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::print_int(int i, bool possible)
{
	std::cout << "Int    " << H_SEP;
	if (possible)
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::print_float(std::string f)
{
	std::cout << "Float  " << H_SEP << f << std::endl;
}

void	ScalarConverter::print_float(float f, bool possible)
{
	std::cout << "Float  " << H_SEP;
	if (possible)
	{
		std::string			tmp;
		std::stringstream	ss;

		ss << f;
		if (strchr(ss.str().c_str(), '.'))
			tmp = ss.str() + "f";
		else
			tmp = ss.str() + ".0f";
		std::cout << tmp << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::print_double(std::string d)
{
	std::cout << "Double " << H_SEP << d << std::endl;
}

void	ScalarConverter::print_double(double d, bool possible)
{
	std::cout << "Double " << H_SEP;
	if (possible)
	{
		std::string			tmp;
		std::stringstream	ss;

		ss << d;
		tmp = ss.str();
		if (!strchr(ss.str().c_str(), '.'))
			tmp += ".0";
		std::cout << tmp << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

std::string	ScalarConverter::convert_hex(unsigned char c)
{
	std::stringstream	ss;

	ss << "0x" << std::setfill('0') << std::setw(2) << std::hex
		<< static_cast<short>(c);
	return (ss.str());
}
