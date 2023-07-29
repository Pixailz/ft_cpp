/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Span.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Span.hpp>
/**
 * <object>		object
 * <function>	function()
 */

// Constructor (unsigned int)
Span::Span(size_t len) : _len(len)
{
	debug("Span class created");

	if (this->_list.size())
		for (int i = this->_list.size(); i > 0; i--)
			this->_list.pop_front();
}

// Destructor
Span::~Span(void)
{
	debug("Span class destructed");
}

// Copy Constructor
Span::Span(const Span &copy)
{
	debug("Span class created (by copy)");
	*this = copy;
}

// '=' operator
Span	&Span::operator=(const Span &src)
{
	debug("Span operator '=' called");
	this->_len = src._len;
	this->_list = src._list;
	return (*this);
}

// Exception

// Other

bool	compare_int(int n1, int n2)
{
	return (n1 > n2);
}

void	Span::addNumber(int n)
{
	if (this->_len < this->_list.size())
		throw std::out_of_range(H_ERROR "Span out of space");
	this->_list.push_back(n);
}

size_t	Span::shortestSpan(void)
{
	if (this->_list.size() < 2)
		throw std::length_error(H_ERROR "Span is not long enought");
	this->_list.sort(compare_int);
	size_t	gap = std::numeric_limits<size_t>::max();
	int		previous = -std::numeric_limits<size_t>::max();
	size_t	current_gap;

	for (	std::list<int>::iterator it = this->_list.begin();
			it != this->_list.end(); it++)
	{
		current_gap = abs(*it - previous);
		if (current_gap < gap)
			gap = current_gap;
		previous = *it;
	}
	return (gap);
}

size_t	Span::longestSpan(void)
{
	if (this->_list.size() < 2)
		throw std::length_error(H_ERROR "Span is not long enought");
	this->_list.sort(compare_int);
	return (abs(this->_list.front()  - this->_list.back()));
}
