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

# include "main.h"

// Constructor (void)
PmergeMeVector::PmergeMeVector(void)
{
	debug("PmergeMeVector class created");
}

PmergeMeVector::PmergeMeVector(char **av)
{
	int	i = 0;
	int	j = 0;
	int	k = 1;
	std::string	tmp_n;

	while (av[k])
	{
		std::string	tmp = av[k];
		i = 0;
		j = 0;
		while (tmp[i])
		{
			while (tmp[i] == ' ')
				i++;
			if (i == (int)tmp.size())
				break ;
			j = i;
			while (tmp[j] && tmp[j] != ' ')
				j++;
			tmp_n = tmp.substr(i, j - i);
			this->_array.push_back(parse_number(tmp_n));
			i = j;
		}
		k++;
	}
	this->_has_odd = false;
	this->_array_len = this->_array.size();
	if (this->_array_len == 0)
		throw ParsingError();
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

vec PmergeMeVector::get_array(void)
{ return (this->_array); }

// Other

void	PmergeMeVector::start_sorting(void)
{
	if (this->_array_len % 2)
	{
		this->_has_odd = true;
		this->_odd = this->_array.back();
		this->_array.pop_back();
		this->_array_len--;
	}
	this->create_pair();
	this->compare_pair();
	// sort pair
	this->mergeSort(this->_pair_array);
	this->mergeInsert();
}

void	PmergeMeVector::compare_pair(void)
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
	vec	tmp;

	for (vecIt it = this->_array.begin(); it != this->_array.end(); it += 2)
	{
		tmp.clear();
		tmp.push_back(*(it));
		tmp.push_back(*(it + 1));
		this->_pair_array.push_back(tmp);
	}
}

void	PmergeMeVector::mergeSort(vecVec &array)
{
	int	array_len = array.size();
	if (array_len <= 1)
		return ;

	int		middle = array_len / 2;
	vecVec	left_array;
	vecVec	right_array;

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
	vecVec &left_array,
	vecVec &right_array,
	vecVec &array
)
{
	int	left_array_len = left_array.size();
	int	right_array_len = right_array.size();
	int	i = 0, l = 0, r = 0;

	while (l < left_array_len && r < right_array_len)
	{
		if (*(left_array[l].begin() + 1) < *(right_array[r].begin() + 1))
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


void	PmergeMeVector::mergeInsert(void)
{
	size_t	base = 0;
	bool	inserted = false;
	vec		smallest;
	this->_array.clear();

	for (vecVecIt it = this->_pair_array.begin(); it != this->_pair_array.end(); it++)
	{
		this->_array.push_back(*(it->begin() + 1));
		smallest.push_back(*(it->begin()));
	}
	if (this->_has_odd)
		smallest.push_back(this->_odd);
	for (vecIt it = smallest.begin(); it != smallest.end(); it++)
	{
		inserted = false;
		if (base == this->_array.size())
			base--;
		for (int i = base; i >= 0; i--)
		{
			if (*it > this->_array.at(i))
			{
				this->_array.insert(this->_array.begin() + i + 1, *it);
				inserted = true;
				break;
			}
		}
		if (!inserted)
			this->_array.insert(this->_array.begin(), *it);
		base += 2;
	}
}
