/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ScalarConverter.cpp                    | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include "ScalarConverter.hpp"
/**
 * <object>		object
 * <function>	function()
 */

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
	*this = copy;
	debug("ScalarConverter class created (by copy)");
}

// '=' operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	this->set_input(src.get_input(), false);
	this->set_type(src.get_type());
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

// Setter
void	ScalarConverter::set_input(std::string input, bool prot) {
	if (prot && input.length() == 0) {
		throw ScalarConverter::EmptyInputErr();
	}
	this->_input = input;
}

void	ScalarConverter::set_input_char(t_uint8 input) {
	this->_input_char = input;
}

void	ScalarConverter::set_input_int(int input) {
	this->_input_int = input;
}

void	ScalarConverter::set_input_float(float input) {
	this->_input_float = input;
}

void	ScalarConverter::set_input_double(double input) {
	this->_input_double = input;
}

void	ScalarConverter::set_status(t_uint8 type) {
	this->_status = type;
}

void	ScalarConverter::set_type(t_uint8 type) {
	this->_type = type;
}

// Getter
std::string	ScalarConverter::get_input(void) const {
	return (this->_input);
}

std::string	ScalarConverter::get_input_char_hex(void) const {
	std::stringstream	ss;

	ss << "0x" << std::setfill('0') << std::setw(2) << std::hex
		<< (short)this->get_input_char();
	return (ss.str());
}

t_uint8	ScalarConverter::get_input_char(void) const {
	return (this->_input_char);
}

int		ScalarConverter::get_input_int(void) const {
	return (this->_input_int);
}

float	ScalarConverter::get_input_float(void) const {
	return (this->_input_float);
}

double	ScalarConverter::get_input_double(void) const {
	return (this->_input_double);
}

t_uint8	ScalarConverter::get_status(void) const {
	return(this->_status);
}

t_uint8	ScalarConverter::get_type(void) const {
	return (this->_type);
}

std::string	ScalarConverter::get_type_str(void) {
	switch (this->get_type()) {
		case CHAR:		return (H_CHAR) ;
		case INT:		return (H_INT) ;
		case FLOAT:		return (H_FLOAT) ;
		case DOUBLE:	return (H_DOUBLE) ;
	}
	return (H_UNKNOWN);
}

// Other
void	ScalarConverter::clear(void) {
	this->set_input("", false);
	this->set_input_char(0);
	this->set_input_int(0);
	this->set_input_float(0);
	this->set_input_double(0);
	this->set_status(UNKNOW);
	this->set_type(UNKNOW);
}

void	ScalarConverter::convert(std::string s)
{
	this->clear();
	try {
		this->set_input(s, true);
		this->check_type();
		this->translate();
		this->print();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << s << std::endl;
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
	int			index = 0;
	bool		have_dot = false;
	bool		just_have_dot = false;

	if (in[index] == '+' || in[index] == '-')
		index++;
	if (in[in.length() - 1] != 'f' && in[in.length() - 1] != 'F')
		return (false);
	in[in.length() - 1] = 0;
	index--;
	while (in[++index])
	{
		if (in[index] == '.')
		{
			if (have_dot == true)
				return (false);
			have_dot = true;
			just_have_dot = true;
			continue;
		}
		if (in[index] >= '0' && in[index] <= '9')
		{
			if (just_have_dot)
				just_have_dot = false;
			continue;
		}
		return (false);
	}
	if (just_have_dot)
		return (false);
	return (true);
}

bool	ScalarConverter::is_double(std::string in)
{
	int			index = 0;
	bool		have_dot = false;
	bool		just_have_dot = false;

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
			just_have_dot = true;
			continue;
		}
		if (in[index] >= '0' && in[index] <= '9')
		{
			if (just_have_dot)
				just_have_dot = false;
			continue;
		}
		return (false);
	}
	if (just_have_dot)
		return (false);
	return (true);
}

void	ScalarConverter::check_type(void)
{
	std::string	input = this->get_input();
	t_uint8		type = UNKNOW;

	if (this->is_char(input)) { type = CHAR; }
	else if (this->is_int(input)) { type = INT; }
	else if (this->is_float(input)) { type = FLOAT; }
	else if (this->is_double(input)) { type = DOUBLE; }
	else {
		if (input == "-inff" || input == "+inff" || input == "nanf") {
			type = FLOAT;
		}
		else if (input == "-inf" || input == "+inf" || input == "nan") {
			type = DOUBLE;
		}
	}
	this->set_type(type);
	std::cout << this->get_type_str() << "[" << input << "]" << std::endl;
}

void	ScalarConverter::translate_char(t_uint8 in) {
	t_uint8 status = UNKNOW;

	this->set_input_char(in);
	this->set_input_int(in);
	this->set_input_float(in);
	this->set_input_double(in);
	if (in <= std::numeric_limits<t_uint8>::max()
	&&	in >= std::numeric_limits<t_uint8>::min())
		status |= CHAR;
	this->set_status(status | INT | FLOAT | DOUBLE);
}

void	ScalarConverter::translate_int(std::string in) {
	long long int	integer;
	t_uint8			status = UNKNOW;

	std::stringstream(in) >> integer;

	if (integer <= std::numeric_limits<int>::max()
	&&	integer >= std::numeric_limits<int>::min())
		status |= INT | FLOAT | DOUBLE;
	if (integer <= std::numeric_limits<char>::max()
	&&	integer >= std::numeric_limits<char>::min())
		status |= CHAR;
	this->set_status(status);
	this->set_input_char(integer);
	this->set_input_int(integer);
	this->set_input_float(integer);
	this->set_input_double(integer);
}

void	ScalarConverter::translate_float(std::string in) {
	float	floating;
	t_uint8	status = UNKNOW;

	if (in == "nanf" || in == "+inff" || in == "-inff")
		status |= FLOAT | DOUBLE;
	else {
		std::stringstream(in) >> floating;

		if ((floating <= std::numeric_limits<float>::max()
		&&	floating >= std::numeric_limits<float>::min())
		||	floating == 0)
			status |= FLOAT | DOUBLE;
		if (floating <= std::numeric_limits<int>::max()
		&&	floating >= std::numeric_limits<int>::min())
			status |= INT;
		if (floating <= std::numeric_limits<char>::max()
		&&	floating >= std::numeric_limits<char>::min())
			status |= CHAR;
		this->set_input_char(floating);
		this->set_input_int(floating);
		this->set_input_float(floating);
		this->set_input_double(floating);
	}
	this->set_status(status);
}

void	ScalarConverter::translate_double(std::string in) {
	double	in_double;
	t_uint8	status = UNKNOW;

	std::stringstream(in) >> in_double;

	if (in == "nan" || in == "+inf" || in == "-inf") {
		status |= FLOAT | DOUBLE;
	}
	else {
		if ((in_double <= std::numeric_limits<double>::max()
		&&	in_double >= std::numeric_limits<double>::min())
		||	in_double == 0)
			status |= DOUBLE;
		if ((in_double <= std::numeric_limits<float>::max()
		&&	in_double >= std::numeric_limits<float>::min())
		||	in_double == 0)
			status |= FLOAT;
		if (in_double <= std::numeric_limits<int>::max()
		&&	in_double >= std::numeric_limits<int>::min())
			status |= INT;
		if (in_double <= std::numeric_limits<char>::max()
		&&	in_double >= std::numeric_limits<char>::min())
			status |= CHAR;
		this->set_input_char(in_double);
		this->set_input_int(in_double);
		this->set_input_float(in_double);
		this->set_input_double(in_double);
	}
	this->set_status(status);
}

void	ScalarConverter::translate(void) {
	t_uint8		type = this->get_type();
	std::string	input = this->get_input();

	if (type == UNKNOW) {
		throw ScalarConverter::UnknownTypeConversionErr();
	}
	else if (type == CHAR)
		this->translate_char(input[1]);
	else if (type == INT)
		this->translate_int(input);
	else if (type == FLOAT)
		this->translate_float(input);
	else if (type == DOUBLE)
		this->translate_double(input);
}

void	ScalarConverter::print_char(void) {
	std::cout << "Char   " << H_SEP;
	if (this->get_status() & CHAR) {
		if (std::isprint(this->get_input_char()))
			std::cout << "'" << this->get_input_char() << "'" << std::endl;
		else
			std::cout << this->get_input_char_hex() << " (Non displayable)" << std::endl;
	}
	else {
		std::cout << "impossible" << std::endl;
	}
}

void	ScalarConverter::print_int(void) {
	std::cout << "Int    " << H_SEP;
	if (this->get_status() & INT)
		std::cout << this->get_input_int() << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::print_float(void) {
	std::string	tmp;
	std::string	tmp_input = this->get_input();
	float		tmp_float = this->get_input_float();

	std::cout << "Float  " << H_SEP;
	if (this->get_status() & FLOAT)
	{
		std::stringstream ss;
		ss << tmp_float;
		if (strchr(ss.str().c_str(), '.'))
			tmp = ss.str() + "f";
		else
			tmp = ss.str() + ".0f";
		if (tmp_input == "nanf" || tmp_input == "nan")
			tmp = "nanf";
		else if (tmp_input == "+inff" || tmp_input == "+inf")
			tmp = "+inff";
		else if (tmp_input == "-inff" || tmp_input == "-inf")
			tmp = "-inff";
		std::cout << tmp << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::print_double(void) {
	std::string	tmp;
	std::string	tmp_input = this->get_input();
	double		tmp_double = this->get_input_double();

	std::cout << "Double " << H_SEP;
	if (this->get_status() & DOUBLE)
	{
		std::stringstream ss;
		ss << tmp_double;
		tmp = ss.str();
		if (!strchr(ss.str().c_str(), '.'))
			tmp += ".0";
		if (tmp_input == "nanf" || tmp_input == "nan")
			tmp = "nan";
		else if (tmp_input == "+inff" || tmp_input == "+inf")
			tmp = "+inf";
		else if (tmp_input == "-inff" || tmp_input == "-inf")
			tmp = "-inf";
		std::cout << tmp << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::print(void)
{
	std::string	tmp;

	this->print_char();
	this->print_int();
	this->print_float();
	this->print_double();
}
