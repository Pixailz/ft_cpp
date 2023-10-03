/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−06−18T05:56:28+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "PmergeMeVector.hpp"
// #include "PmergeMeDeque.hpp"

const char *ParsingError::what() const throw()
{ return ("Inputed string isn't good"); }

int	parse_number(std::string n)
{
	int			i = 0;
	long int	j = 0;

	while(n[i])
	{
		if (!is_good_number(n[i]))
			throw ParsingError();
		i++;
	}
	j = std::atol(n.c_str());
	if (j > std::numeric_limits<int>::max() ||
		j < -std::numeric_limits<int>::max())
		throw ParsingError();
	return (static_cast<int>(j));
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		err("Not enought args");
		return (1);
	}
	try
	{
		{
			timeval	begin;
			timeval	end;

			gettimeofday(&begin, NULL);
			PmergeMeVector	vector_test(av[1]);
			print_vec_t("std::vector: before", vector_test.get_array());

			vector_test.start_sorting();
			gettimeofday(&end, NULL);
			print_vec_t("std::vector: after", vector_test.get_array());
			display_elapsed_time_usec("std::vector", begin, end);
		}
	}
	catch (std::exception &e)
	{ err(e.what()); }
	return (0);
}
