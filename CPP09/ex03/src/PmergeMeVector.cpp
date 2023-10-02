/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		PmergeMeVector.cpp                     | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <PmergeMeVector.hpp>
/**
 * <object>		object
 * <function>	function()
 */

// Constructor (void)
PmergeMeVector::PmergeMeVector(void)
{
	debug("PmergeMeVector class created");
}

PmergeMeVector::PmergeMeVector(std::string array)
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
	this->_array_len = this->_array.size();
	debug("PmergeMeVector class created");
}

// Destructor
PmergeMeVector::~PmergeMeVector(void)
{
	debug("PmergeMeVector class destructed");
}

// Copy Constructor
PmergeMeVector::PmergeMeVector(const PmergeMeVector &copy)
{
	debug("PmergeMeVector class created (by copy)");
	*this = copy;
}

// '=' operator
PmergeMeVector	&PmergeMeVector::operator=(const PmergeMeVector &src)
{
	(void)src;
	debug("PmergeMeVector operator '=' called");
	return (*this);
}

// Exception

// Setter

// Getter

std::vector<int> PmergeMeVector::get_array(void)
{ return (this->_array); }

// Other

void	PmergeMeVector::start_sorting(void)
{
	if (this->_array_len % 2)
	{
		this->_has_straggler = true;
		this->_straggler = this->_array.back();
		this->_array.pop_back();
		this->_array_len--;
	}
	this->create_pair();
	this->sort_pair();
	this->sort_pair_array();
}

void	PmergeMeVector::sort_pair_array(void)
{
//TODO
}

void	PmergeMeVector::sort_pair(void)
{
	for (vecVecIt it = this->_pair_array.begin(); it != this->_pair_array.end(); it++)
	{
		vecIt itt = it->begin();
		if (*itt > *(itt + 1))
		{
			*itt ^= *(itt + 1);
			*(itt + 1) ^= *itt;
			*itt ^= *(itt + 1);
		}
	}
}

void	PmergeMeVector::create_pair(void)
{
	std::vector<arrType>	tmp;

	for (int i = 0; i < (int)this->_array_len; i += 2)
	{
		tmp.clear();
		tmp.push_back(this->_array.back());
		this->_array.pop_back();
		tmp.push_back(this->_array.back());
		this->_array.pop_back();
		this->_pair_array.push_back(tmp);
	}
}

void	PmergeMeVector::mergeSort(std::vector<arrType> &array)
{
	int	array_len = array.size();
	if (array_len <= 1)
		return ;

	int middle = array_len / 2;
	std::vector<arrType>	left_array;
	std::vector<arrType>	right_array;
	left_array.reserve(middle);
	right_array.reserve(array_len - middle);

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

void	PmergeMeVector::merge(
	std::vector<arrType> &left_array,
	std::vector<arrType> &right_array,
	std::vector<arrType> &array
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
