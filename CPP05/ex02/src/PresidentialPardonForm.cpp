/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		PresidentialPardonForm.hpp             | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <PresidentialPardonForm.hpp>
/**
 * <object>		object
 * <function>	function()
 */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 145, 137)
{
	AForm::set_target(target);
	debug("PresidentialPardonForm class created");
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	debug("PresidentialPardonForm class destructed");
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	*this = src;
	debug("PresidentialPardonForm operator '=' called");
	return (*this);
}

void	PresidentialPardonForm::execute_specific(Bureaucrat const &executor)
{
	std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox, executed by " \
		<< executor.get_name() << std::endl;
}
