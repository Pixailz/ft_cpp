/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Form.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Form.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	Form::check_exception(void)
{
	if (this->_sign_req_grade < 1 || this->_exec_req_grade < 1)
		throw Form::GradeTooHighException();
	if (this->_sign_req_grade > 150 || this->_exec_req_grade > 150)
		throw Form::GradeTooLowException();
	if (this->_name.length() == 0)
		throw Form::EmptyNameException();
}

Form::Form(std::string name, int sign_grade, int exec_grade) :
_name(name), _sign_req_grade(sign_grade), _exec_req_grade(exec_grade)
{
	this->check_exception();
	_signed = false;
	debug("Form class created");
}

Form::~Form(void)
{
	debug("Form class destructed");
}

Form::Form(const Form &copy) :
_name(copy._name), _sign_req_grade(copy._sign_req_grade), _exec_req_grade(copy._exec_req_grade)
{
	this->check_exception();
	this->_signed = copy._signed;
	debug("Form class created (by copy)");
	*this = copy;
}

Form	&Form::operator=(const Form &src)
{
	this->_signed = src._signed;
	debug("Form operator '=' called");
	return (*this);
}

int	Form::get_grade_sign(void) const
{
	return (this->_sign_req_grade);
}

int	Form::get_grade_exec(void) const
{
	return (this->_exec_req_grade);
}

std::string	Form::get_name(void) const
{
	return (this->_name);
}

bool	Form::get_is_signed(void) const
{
	return (this->_signed);
}

void	Form::be_signed(Bureaucrat signatory)
{
	if (this->_sign_req_grade >= signatory.get_grade())
	{
		if (this->_signed)
			throw Form::AlreadySigned();
		else
			this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out_stream, const Form &src)
{
	out_stream << "Form (" << G << src.get_name() << RST << ") details :" << std::endl \
		<< "  Grade required to sign:\x1b[30G[" << src.get_grade_sign() << "]" << std::endl \
		<< "  Grade required to exec:\x1b[30G[" << src.get_grade_exec() << "]" << std::endl \
		<< "  Is Signed ?\x1b[30G";
	out_stream << (src.get_is_signed() ? G "True" RST : R "False" RST);
	return (out_stream);
}
