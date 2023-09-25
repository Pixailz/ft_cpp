/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		RPN.cpp                                | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <RPN.hpp>
/**
 * <object>		object
 * <function>	function()
 */

std::string trim(std::string str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(' ');
	return (str.substr(first, (last - first + 1)));
}

// Constructor (void)
RPN::RPN(void)
{
	debug("RPN class created");
}

RPN::RPN(std::string expr): _expr(trim(expr))
{
	debug("RPN class created with the following expression: " + this->_expr);
}

// Destructor
RPN::~RPN(void)
{
	debug("RPN class destructed");
}

// Copy Constructor
RPN::RPN(const RPN &copy)
{
	debug("RPN class created (by copy)");
	*this = copy;
}

// '=' operator
RPN	&RPN::operator=(const RPN &src)
{
	(void)src;
	debug("RPN operator '=' called");
	return (*this);
}

// Exception
const char *RPN::WrongExpression::what() const throw()
{
	return (H_ERROR "Wrong expresion");
}

RPN::UnexpectedCharAt::UnexpectedCharAt(int i): _at(i) {};

const char *RPN::UnexpectedCharAt::what() const throw()
{
	return (H_ERROR "Wrong expresion");
}

// Other

bool	is_good_number(char n)
{
	return (n >= '0' && n <= '9');
}

bool	is_good_operator(char n)
{
	return (AVAILABLE_OPERATOR.find(n) != std::string::npos);
}

bool	is_good_char(char n)
{
	return (is_good_number(n) || is_good_operator(n));
}

void	RPN::process_number(char c)
{
	this->_stack.push(std::atoi(c));
}

void	RPN::process_operator(char c)
{

}

void	RPN::calculate(void)
{
	int	len_expr = (int)this->_expr.length();
	int	i = 0;
	char c;

	while (this->_expr[i])
	{
		c = this->_expr[i];
		if (is_good_number(c))
			this->process_number(c);
		else if(is_good_operator(c))
			this->process_operator(c);
		else
		{
			err("Unexpected char at pos", i);
			break ;
		}
		i++;
		while (this->_expr[i] == ' ')
			i++;
	}
}
