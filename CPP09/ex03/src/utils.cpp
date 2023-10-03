#include "main.h"

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

bool	is_arr_sorted(vecVec array)
{
	vecVecIt	ite = array.end();
	vecVecIt	it = array.begin();
	arrType		last_seen = *it->end();

	std::cout << "last " << last_seen << std::endl;

	if (ite == it)
		return (true);
	it++;
	if (*(it->end()) > last_seen)
		return (false);
	for (; it != ite; it++)
	{
		if (last_seen > *it->end())
			return (false);
		last_seen = *it->end();
	}
	return (true);
}

void	print_vec_vec(vecVec array)
{
	vecVecIt	ite = array.end();

	for (vecVecIt it = array.begin(); it != ite; it++)
	{
		for (vecIt itt = it->begin(); itt != it->end(); itt++)
			std::cout << *itt << " ";
		std::cout << std::endl;
	}
}

void	print_vec(vec array)
{
	vecIt	ite = array.end();
	int						i = 0;
	int						max_ite = MAX_DISPLAY_N;

	for (vecIt it = array.begin(); it != ite; it++)
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

void	print_vec_t(std::string title, vec array)
{
	std::cout << H_INFO << title << ":" << COL_ARRAY << "[";
	print_vec(array);
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
