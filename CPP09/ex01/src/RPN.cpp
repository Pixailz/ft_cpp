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

std::string to_string(int value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

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

void	print_stack(st sta)
{
	st	copy(sta);

	if (copy.empty())
		std::cout << "empty stack";
	while (!copy.empty())
	{
		std::cout << copy.top() << " ";
		copy.pop();
	}
	std::cout << std::endl;
}

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

RPN::RPN(std::string expr): _expr(expr)
{
	debug("RPN class created with the following expression: \"" + this->_expr + '"');
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
	return ("Wrong expresion");
}

const char *RPN::ExpressionOverflow::what() const throw()
{
	return ("Calculation overflow");
}

const char *RPN::ExpressionUnderflow::what() const throw()
{
	return ("Calculation underflow");
}

const char *RPN::DivisionByZero::what() const throw()
{
	return ("Cannot divide by zero");
}

RPN::UnexpectedCharAt::UnexpectedCharAt(int i)
	: _msg(std::string("Unexpected char at position ") + to_string(i))
{ };

RPN::UnexpectedCharAt::~UnexpectedCharAt() throw()
{ };

const char *RPN::UnexpectedCharAt::what() const throw()
{
	return (this->_msg.c_str());
}

// Other

void	RPN::process_number(const char *c)
{
	std::cout << H_INFO;
	this->_stack.push(std::atoi(c));
	std::cout << this->_stack.top() << " → ";
	print_stack(this->_stack);
}

large_type RPN::take_top_stack(void)
{
	large_type	n;

	if (this->_stack.empty())
		throw WrongExpression();
	n = this->_stack.top();
	this->_stack.pop();
	return (n);
}

void	RPN::process_operator(char c)
{
	large_type	n2 = this->take_top_stack();
	large_type	n1 = this->take_top_stack();
	large_type	result;

	switch (c)
	{
		case ('+') :
		{ result = n1 + n2; break;}
		case ('-') :
		{ result = n1 - n2; break;}
		case ('/') :
		{
			if (n2 == 0)
				throw DivisionByZero();
			result = n1 / n2; break;
		}
		case ('*') :
		{ result = n1 * n2; break;}
	}
	if (result > std::numeric_limits<sttype>::max())
		throw ExpressionOverflow();
	if (result < -std::numeric_limits<sttype>::max())
		throw ExpressionUnderflow();
	std::cout << H_INFO;
	this->_stack.push(result);
	std::cout << c << " → ";
	print_stack(this->_stack);
}

void	RPN::calculate(void)
{
	int		len_expr = (int)this->_expr.length();
	int		i = 0;
	int		i_1 = 0;
	char	c;

	while (this->_expr[i])
	{
		while (this->_expr[i] == ' ')
			i++;
		if (i == len_expr)
			break ;
		c = this->_expr[i];
		i_1 = i + 1;
		if (is_good_number(c))
		{
			if (this->_expr[i_1] && this->_expr[i_1] != ' ')
				throw UnexpectedCharAt(i + 2);
			else
				this->process_number(&c);
		}
		else if(is_good_operator(c))
		{
			if (this->_expr[i_1] && this->_expr[i_1] != ' ')
				throw UnexpectedCharAt(i + 2);
			else
				this->process_operator(c);
		}
		else
			throw UnexpectedCharAt(i + 1);
		i++;
	}
	if (this->_stack.size() != 1)
		throw WrongExpression();
	std::cout << H_INFO "result: " << this->_stack.top() << std::endl;
}
