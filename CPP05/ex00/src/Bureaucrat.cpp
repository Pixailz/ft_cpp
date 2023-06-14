/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Bureaucrat.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include "Bureaucrat.hpp"
/**
 * <object>		object
 * <function>	function()
 */

// Constructor (std::string)
Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	this->_grade = DEFAULT_GRADE;
	if (name.length() == 0)
		throw Bureaucrat::EmptyNameException();
	debug("Bureaucrat class created");
}

// Constructor (std::string, int)
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (name.length() == 0)
		throw Bureaucrat::EmptyNameException();
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	debug("Bureaucrat class created, with grade");
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
	debug("Bureaucrat class destructed");
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	debug("Bureaucrat class created (by copy)");
	*this = copy;
}

// '=' operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	debug("Bureaucrat operator '=' called");
	return (*this);
}

// '<<' operator
std::ostream	&operator<<(std::ostream &out_stream, const Bureaucrat &src)
{
	out_stream << "Hi, i'm " << R << src.get_name() << RST \
		" and my grade is " << G << src.get_grade() << RST \
		" but sorry i " << R << "don't" RST << " have the time for " << \
		G << "you" << RST;
	return (out_stream);
}

// exceptions
const char*	Bureaucrat::EmptyNameException::what() const throw()
{
	return (H_ERROR "Name cannot be empty");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return (H_ERROR "Grade to high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return (H_ERROR "Grade to low");
}

// Getters
std::string	Bureaucrat::get_name(void) const
{
	return (this->_name);
}

int	Bureaucrat::get_grade(void) const
{
	return (this->_grade);
}

// Others function
void	Bureaucrat::inc_grade(void)
{
	int	current_grade = this->get_grade() - 1;

	if (current_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = current_grade;
}

void	Bureaucrat::dec_grade(void)
{
	int	current_grade = this->get_grade() + 1;

	if (current_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = current_grade;
}
