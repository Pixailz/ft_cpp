/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		RobotomyRequestForm.hpp                | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <RobotomyRequestForm.hpp>
/**
 * <object>		object
 * <function>	function()
 */

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
	AForm::set_target(target);
	debug("RobotomyRequestForm class created");
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	debug("RobotomyRequestForm class destructed");
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	*this = src;
	debug("RobotomyRequestForm operator '=' called");
	return (*this);
}

void	RobotomyRequestForm::execute_specific(Bureaucrat const &executor)
{
	std::ifstream	infile("/dev/urandom");
	char			random_char;

	std::cout << "**Devicerate some brainz**" << std::endl;
	if (infile.is_open())
		random_char = infile.get();
	if (random_char % 2)
	{
		std::cout << executor.get_name() << " successfully robotmised " \
			<< this->get_target() << std::endl;
	}
	else
	{
		std::cout << executor.get_name() << " don't successfully robotmised " \
			<< this->get_target() << std::endl;
	}
	infile.close();
}
