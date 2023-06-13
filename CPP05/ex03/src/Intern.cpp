/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Intern.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include "Intern.hpp"
/**
 * <object>		object
 * <function>	function()
 */


Intern::Intern(void)
{
	debug("Intern class created");
}

Intern::~Intern(void)
{
	debug("Intern class destructed");
}

Intern::Intern(const Intern &copy)
{
	debug("Intern class created (by copy)");
	*this = copy;
}

Intern	&Intern::operator=(const Intern &src)
{
	*this = src;
	debug("Intern operator '=' called");
	return (*this);
}

AForm *create_shruberry(std::string const & target)
{
	return (new ShruberryCreationForm(target));
}

AForm *create_robotomy(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm *create_pardon(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::make_form(std::string name, std::string target)
{
	const t_typeForm	name_available[] = {
		{"Shrubz", create_shruberry},
		{"Robotomy", create_robotomy},
		{"Presidential", create_pardon}
	};

	for (int i = 0; i < 3; i++) {
		if (name_available[i].name == name)
			return (name_available[i].func(target));
	}
	throw Intern::CannotCreatForm();
}
