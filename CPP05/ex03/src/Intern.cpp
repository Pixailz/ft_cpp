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

// Constructor (void)
Intern::Intern(void)
{
	this->_id = 0;
	debug("Intern class created");
}

// Constructor (int)
Intern::Intern(int id)
{
	this->_id = id;
	debug("Intern class created");
}

// Copy constructor
Intern::Intern(const Intern &copy)
{
	debug("Intern class created (by copy)");
	*this = copy;
}

// Destructor
Intern::~Intern(void)
{
	debug("Intern class destructed");
}

// '=' operator
Intern	&Intern::operator=(const Intern &src)
{
	this->_id = src._id;
	debug("Intern operator '=' called");
	return (*this);
}

// exception

const char*	Intern::CannotCreatForm::what() const throw()
{
	return (H_ERROR "Intern cannot create not found form");
}

// Setter
void	Intern::set_id(int id)
{
	this->_id = id;
}

// Getter
int		Intern::get_id(void)
{
	return (this->_id);
}

// Others
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
		{
			std::cout << "Intern, id " << this->get_id() << " can create form "
				<< name << " (" << target << ")" << std::endl;
			return (name_available[i].func(target));
		}
	}
	throw Intern::CannotCreatForm();
}
