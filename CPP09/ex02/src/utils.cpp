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
	std::cout << H_INFO << title << ":" << COL_ARRAY << "top [";
	print_vec(array);
	std::cout << "] back" << std::endl;
}

void	print_deq(deq array)
{
	deqIt	ite = array.end();
	int						i = 0;
	int						max_ite = MAX_DISPLAY_N;

	for (deqIt it = array.begin(); it != ite; it++)
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

void	print_deq_t(std::string title, deq array)
{
	std::cout << H_INFO << title << ":" << COL_ARRAY << "top [";
	print_deq(array);
	std::cout << "] back" << std::endl;
}

std::string	get_doted_time(ts elapsed_us)
{
	std::ostringstream oss;
	oss << std::setprecision(20) << elapsed_us;
	std::string tmp = oss.str();
	size_t tmp_size = tmp.size();
	size_t tmp_len = tmp_size / 3;
	if (tmp_len && !(tmp_size % 3))
		tmp_len--;
	std::string result = "";
	for (size_t i = 0; i < tmp_len; i++)
	{
		tmp_size = tmp.size();
		result += "," + tmp.substr(tmp_size - 3, 3);
		tmp = tmp.substr(0, tmp_size - 3);
	}
	return (tmp + result);
}

void	display_elapsed_time_usec(std::string title, timeval begin, timeval end)
{
	ts	elapsed_us = (
		(end.tv_sec - begin.tv_sec) * 1000000
	) + (
		(end.tv_usec - begin.tv_usec) % 1000000
	);

	std::cout << H_INFO << title << ": elapsed time" << COL_ARRAY
		<< get_doted_time(elapsed_us) << MICRO_SEC_STR
		<< std::endl;
}

std::string to_string(int value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
