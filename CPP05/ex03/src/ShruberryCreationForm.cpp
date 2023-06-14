/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ShruberryCreationForm.hpp              | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <ShruberryCreationForm.hpp>
/**
 * <object>		object
 * <function>	function()
 */

ShruberryCreationForm::ShruberryCreationForm(std::string target) : AForm("Shrubz", 145, 137)
{
	AForm::set_target(target);
	debug("ShruberryCreationForm class created");
}

void	ShruberryCreationForm::execute_specific(Bureaucrat const &executor)
{
	std::string		target_name = AForm::get_target() + "_shruberry";
	std::ofstream	target_file;

	target_file.open(target_name.c_str());
	if (target_file.is_open())
	{
		for (int i = 0; i < 2; i++)
		{
			target_file << "         . . .                                "<< std::endl;
			target_file << "        .        .  .     ..    .             " << std::endl;
			target_file << "     .                 .         .  .         " << std::endl;
			target_file << "                     .                        " << std::endl;
			target_file << "                    .                ..       " << std::endl;
			target_file << "    .          .            .              .  " << std::endl;
			target_file << "    .            '.,        .               . " << std::endl;
			target_file << "    .              'b      *                  " << std::endl;
			target_file << "     .              '$    #.                .." << std::endl;
			target_file << "  ..      .  ..      *#  @):        .   . .   " << std::endl;
			target_file << "               .     :@,@):   ,.**:'   .      " << std::endl;
			target_file << "   .      .,         :@@*: ..**'      .   .   " << std::endl;
			target_file << "            '#o.    .:(@'.@*\"'  .             " << std::endl;
			target_file << "    .  .       'bq,..:,@@*'   ,*      .  .    " << std::endl;
			target_file << "               ,p$q8,:@)'  .p*'      .        " << std::endl;
			target_file << "        .     '  . '@@Pp@@*'    .  .          " << std::endl;
			target_file << "         .  . ..    Y7'.'     .  .            " << std::endl;
			target_file << "                   :@):.                      " << std::endl;
			target_file << "                  .:@:'.                      " << std::endl;
			target_file << "                .::(@:.      -Sam Blumenstein-" << std::endl;
		}
	}
	target_file.close();
	std::cout << executor.get_name() << " successfully executed " \
		<< this->get_target() << " (" << this->get_target() << ")" << std::endl;
}
