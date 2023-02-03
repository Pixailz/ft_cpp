/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Harl.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include "Harl.hpp"

/*#BEGIN#_______________________>#_|PRIVATE|_#<_____________________________##*/

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
			  << "\tI love having extra bacon for my"
			  << " 7XL-double-cheese-triple-pickle-specialketchup burger."
			  << " I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
			  << "\tI cannot believe adding extra bacon costs more money."
			  << " You didn’t put enough bacon in my burger! If you did,"
			  << " I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
			  << "\tI think I deserve to have some extra bacon for free."
			  << " I’ve been coming for years whereas you started working"
			  << " here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl
			  << "\tThis is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

/*#END#_________________________<#_|PRIVATE|_#>_____________________________##*/

/*#BEGIN#________________________>#_|PUBLIC|_#<_____________________________##*/

/*#BEGIN#_____________________>#_|CONSTRUCTOR|_#<___________________________##*/

Harl::Harl(void) { }
//{
//	std::cout << "Harl class created\n";
//}

/*#END#_______________________<#_|CONSTRUCTOR|_#>___________________________##*/

/*#BEGIN#______________________>#_|DESTRUCTOR|_#<___________________________##*/

Harl::~Harl(void) { }
//{
//	std::cout << "Harl class destructed\n";
//}

/*#END#________________________<#_|DESTRUCTOR|_#>___________________________##*/

/*#BEGIN#________________________>#_|OTHER|_#<______________________________##*/

void	Harl::complain(std::string level)
{
	void	(Harl::*function_array[NB_FUNCTION])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string complain_level[NB_FUNCTION] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	complain_id;

	for (complain_id = 0; complain_id < NB_FUNCTION; complain_id++)
		if (level == complain_level[complain_id])
			break ;
	if (complain_id == NB_FUNCTION)
		std::cout << "wrong harl complain level" << std::endl;
	else
		(this->*function_array[complain_id])();
}

/*#END#__________________________<#_|OTHER|_#>______________________________##*/

/*#END#__________________________<#_|PUBLIC|_#>_____________________________##*/
