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

# define MAX_DISPLAY_N		15;

void	debug(std::string msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

void	err(std::string msg)
{
	std::cerr << H_ERROR << msg << std::endl;
}

void	err(std::string title, std::string msg)
{
	std::cerr << H_ERROR << title << " " << msg << std::endl;
}

bool	is_good_number(char n)
{ return (n >= '0' && n <= '9'); }

template <typename T>
void	print_array_t(T array)
{
	typename T::iterator	ite = array.end();
	int						i = 0;
	int						max_ite = MAX_DISPLAY_N;

	for (typename T::iterator it = array.begin(); it != ite; it++)
	{
		std::cout << *it;
		i++;
		if (it + 1 != ite)
			std::cout << " ";
		if (max_ite == i)
		{
			std::cout << "...";
			break ;
		}
	}
}

void	print_array_array_t(vecVec array)
{
	vecVecIt	ite = array.end();

	for (vecVecIt it = array.begin(); it != ite; it++)
	{
		for (vecIt itt = it->begin(); itt != it->end(); itt++)
			std::cout << *itt << " ";
		std::cout << std::endl;
	}
}

template <typename T>
void	print_array(std::string title, T array)
{
	std::cout << H_INFO << title << ":" << COL_ARRAY << "[";
	print_array_t(array);
	std::cout << "]" << std::endl;
}


void	display_elapsed_time_usec(std::string title, timeval begin, timeval end)
{
	ts	elapsed_us = (
		(end.tv_sec - begin.tv_sec) * 1000000
	) + (
		(end.tv_usec - begin.tv_usec) % 1000000
	);

	std::cout << H_INFO << title << ": elapsed time" << COL_ARRAY
		<< std::setprecision(20) << elapsed_us << MICRO_SEC_STR
		<< std::endl;
}

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
			print_array("std::vector: before", vector_test.get_array());

			vector_test.start_sorting();
			gettimeofday(&end, NULL);
			print_array("std::vector: after", vector_test.get_array());
			display_elapsed_time_usec("std::vector", begin, end);
		}
	}
	catch (std::exception &e)
	{ err(e.what()); }
	return (0);
}
