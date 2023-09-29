/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		PmergeMeDeque.cpp                      | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <PmergeMeDeque.hpp>
/**
 * <object>		object
 * <function>	function()
 */

// Constructor (void)
PmergeMeDeque::PmergeMeDeque(void)
{
	debug("PmergeMeDeque class created");
}

PmergeMeDeque::PmergeMeDeque(std::string array)
{
	int	i = 0;
	int	j = 0;
	int	len_array = (int)array.size();
	std::string	tmp_n;

	while (array[i])
	{
		while (array[i] == ' ')
			i++;
		if (i == len_array)
			break ;
		j = i;
		while (array[j] && array[j] != ' ')
			j++;
		tmp_n = array.substr(i, j - i);
		this->_array.push_back(parse_number(tmp_n));
		i = j;
	}
	debug("PmergeMeDeque class created");
}

// Destructor
PmergeMeDeque::~PmergeMeDeque(void)
{
	debug("PmergeMeDeque class destructed");
}

// Copy Constructor
PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &copy)
{
	debug("PmergeMeDeque class created (by copy)");
	*this = copy;
}

// '=' operator
PmergeMeDeque	&PmergeMeDeque::operator=(const PmergeMeDeque &src)
{
	(void)src;
	debug("PmergeMeDeque operator '=' called");
	return (*this);
}

// Exception

// Setter

// Getter

std::deque<int> PmergeMeDeque::get_array(void)
{ return (this->_array); }

// Other

void	PmergeMeDeque::start_sorting(void)
{
	this->mergeSort(this->_array);
}

void	PmergeMeDeque::mergeSort(std::deque<arrType> &array)
{
	int	array_len = array.size();
	if (array_len <= 1)
		return ;

	int middle = array_len / 2;
	std::deque<arrType>	left_array;
	std::deque<arrType>	right_array;

	for (int i = 0; i < array_len; i++)
	{
		if (i < middle)
			left_array.push_back(array[i]);
		else
			right_array.push_back(array[i]);
	}
	this->mergeSort(left_array);
	this->mergeSort(right_array);
	this->merge(left_array, right_array, array);
}

void	PmergeMeDeque::merge(
	std::deque<arrType> &left_array,
	std::deque<arrType> &right_array,
	std::deque<arrType> &array
)
{
	int	left_array_len = left_array.size();
	int	right_array_len = right_array.size();
	int	i = 0, l = 0, r = 0;

	while (l < left_array_len && r < right_array_len)
	{
		if (left_array[l] < right_array[r])
			array[i] = left_array[l++];
		else
			array[i] = right_array[r++];
		i++;
	}
	while (l < left_array_len)
		array[i++] = left_array[l++];
	while (r < right_array_len)
		array[i++] = right_array[r++];
}
