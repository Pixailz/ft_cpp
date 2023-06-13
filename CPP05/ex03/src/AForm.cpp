/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		AForm.cpp                              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <AForm.hpp>
/**
 * <object>		object
 * <function>	function()
 */

void	AForm::check_exception(void)
{
	if (this->_sign_req_grade < 1 || this->_exec_req_grade < 1)
		throw AForm::GradeTooHighException();
	if (this->_sign_req_grade > 150 || this->_exec_req_grade > 150)
		throw AForm::GradeTooLowException();
	if (this->_name.length() == 0)
		throw AForm::EmptyNameException();
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) :
_name(name), _sign_req_grade(sign_grade), _exec_req_grade(exec_grade)
{
	this->check_exception();
	_signed = false;
	debug("AForm class created");
}

AForm::~AForm(void)
{
	debug("AForm class destructed");
}

AForm::AForm(const AForm &copy) :
	_name(copy._name),
	_sign_req_grade(copy._sign_req_grade),
	_exec_req_grade(copy._exec_req_grade)
{
	this->check_exception();
	this->_signed = copy._signed;
	debug("AForm class created (by copy)");
	*this = copy;
}

AForm	&AForm::operator=(const AForm &src)
{
	this->_signed = src._signed;
	this->set_target(src.get_target());
	debug("AForm operator '=' called");
	return (*this);
}

void	AForm::execute(Bureaucrat const &executor)
{
	std::string form_name = this->get_name();
	if (!this->_signed)
		throw AForm::NotSigned();
	if (executor.get_grade() > this->get_grade_exec())
		throw AForm::GradeTooLowException();
	this->execute_specific(executor);
}

void	AForm::set_target(std::string target)
{
	if (!target.length())
		throw AForm::EmptyNameException();
	this->_target = target;
}

int	AForm::get_grade_sign(void) const
{
	return (this->_sign_req_grade);
}

int	AForm::get_grade_exec(void) const
{
	return (this->_exec_req_grade);
}

std::string	AForm::get_name(void) const
{
	return (this->_name);
}

std::string	AForm::get_target(void) const
{
	return (this->_target);
}

bool	AForm::get_is_signed(void) const
{
	return (this->_signed);
}

void	AForm::be_signed(Bureaucrat signatory)
{
	if (this->_sign_req_grade >= signatory.get_grade())
	{
		if (this->_signed)
			throw AForm::AlreadySigned();
		else
			this->_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out_stream, const AForm &src)
{
	out_stream << "AForm (" << G << src.get_name() << RST << ") details :" << std::endl \
		<< "  Grade required to sign:\x1b[30G[" << src.get_grade_sign() << "]" << std::endl \
		<< "  Grade required to exec:\x1b[30G[" << src.get_grade_exec() << "]" << std::endl \
		<< "  Is Signed ?\x1b[30G";
	out_stream << (src.get_is_signed() ? G "True" RST : R "False" RST);
	return (out_stream);
}
