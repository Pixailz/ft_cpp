/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		BitcoinExchange.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <BitcoinExchange.hpp>
/**
 * <object>		object
 * <function>	function()
 */

// Constructor (void)
BitcoinExchange::BitcoinExchange(void)
{
	debug("BitcoinExchange class created");
}

BitcoinExchange::BitcoinExchange(std::string input_file):
	_input_file(input_file.c_str()),
	_data_file(DATA_FILE)
{
	debug("BitcoinExchange class created with arg: " + input_file);

	this->_line_nb = 0;
	if (this->_data_file.is_open())
		this->parse_data_file();
	this->_line_nb = 0;
	if (this->_input_file.is_open())
		this->parse_input_file(input_file);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
	debug("BitcoinExchange class destructed");
}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	debug("BitcoinExchange class created (by copy)");
	*this = copy;
}

// '=' operator
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
	debug("BitcoinExchange operator '=' called");
	return (*this);
}

// PARSING

std::string trim(std::string str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(' ');
	return (str.substr(first, (last - first + 1)));
}

bool	is_leap_year(int year)
{
	if (!(year % 4))
	{
		if (!(year % 100))
		{
			if (!(year % 400))
				return (true);
		}
		else
			return (true);
	}
	return (false);
}

bool	is_int(std::string in)
{
	int			index = 0;

	if (in[index] == '+' || in[index] == '-')
		index++;
	while (in[index])
		if (in[index] < '0' || in[index++] > '9')
			return (false);
	return (true);
}

bool	is_decimal(std::string in)
{
	int			index = 0;
	bool		have_dot = false;

	if (in[index] == '+' || in[index] == '-')
		index++;
	index--;
	while (in[++index])
	{
		if (in[index] == '.')
		{
			if (have_dot == true)
				return (false);
			have_dot = true;
			continue;
		}
		if (in[index] >= '0' && in[index] <= '9')
			continue;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::parse_date(std::string date)
{
	std::string	year;
	std::string	month;
	std::string	day;
	int			n_year;
	int			n_month;
	int			n_day;
	int			date_size = (int)date.size();
	int			i = 0;
	int			max_february = 28;

	while (i < date_size)
	{
		if(date[i] != '-')
			year += date[i];
		else
			break ;
		i++;
	}
	i++;
	while (i < date_size)
	{
		if(date[i] != '-')
			month += date[i];
		else
			break ;
		i++;
	}
	i++;
	while (i < date_size)
	{
		if(date[i] != '-')
			day += date[i];
		else
			break ;
		i++;
	}
	if (year == "" || month == "" || day == "")
		return (false);
	if (!is_int(year) || !is_int(month) || !is_int(day))
		return (false);
	n_year = std::atoi(year.c_str());
	n_month = std::atoi(month.c_str());
	n_day = std::atoi(day.c_str());
	if (n_year < 0 || n_month <= 0 || n_day <= 0 || n_month > 12)
		return (false);
	if (is_leap_year(n_year))
		max_february = 29;
	switch(n_month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			if (n_day > 31) return (false);
			break ;
		}
		case 4: case 6: case 9: case 11:
		{
			if (n_day > 30) return (false);
			break ;
		}
		case 2:
		{
			if (n_day > max_february) return (false);
			break ;
		}
	}
	return (true);
}

void	BitcoinExchange::parse_data_file(void)
{
	int	tmp_status = 0;

	getline(this->_data_file, this->_line);
	this->_line_nb++;

	if (!this->data_is_good_first_line())
		err(DATA_FILE, ": wrong first line");
	while(getline(this->_data_file, this->_line))
	{
		this->_line_nb++;
		tmp_status = this->data_is_good_line();
		if (tmp_status == ERR_DATA_WRONG_LINE)
			err(DATA_FILE, ": wrong line, at", this->_line_nb);
		if (tmp_status == ERR_DATA_WRONG_DATE_LINE)
			err(DATA_FILE, ": wrong date, at", this->_line_nb);
		if (tmp_status == ERR_DATA_WRONG_VALUE_LINE)
			err(DATA_FILE, ": wrong value, at", this->_line_nb);
	}
}

bool BitcoinExchange::data_is_good_first_line(void)
{
	this->_line = trim(this->_line);
	return (this->_line == "date,exchange_rate");
}

bool BitcoinExchange::data_is_good_value(std::string value)
{
	return (is_int(value) || is_decimal(value));
}

int BitcoinExchange::data_is_good_line(void)
{
	std::string	tmp_line = trim(this->_line);
	std::string	date;
	std::string	value;
	int			tmp_line_size = (int)tmp_line.size();

	for(int i = 0; i < tmp_line_size; i++){
		if(tmp_line[i] != ',')
			date += tmp_line[i];
		else
			break ;
	}
	if (date.size() == tmp_line.size())
		return (ERR_DATA_WRONG_LINE);
	value = tmp_line.substr(date.size()+1, tmp_line.size() - date.size());
	if (!this->parse_date(date))
		return (ERR_DATA_WRONG_DATE_LINE);
	if (!this->data_is_good_value(value))
		return (ERR_DATA_WRONG_VALUE_LINE);
	this->_data[date] = std::strtod(value.c_str(), NULL);
	return (0);
}

void	BitcoinExchange::parse_input_file(std::string input_file)
{
	int	tmp_status = 0;

	getline(this->_input_file, this->_line);
	this->_line_nb++;

	if (!this->input_is_good_first_line())
		err(input_file, ": wrong first line");
	while(getline(this->_input_file, this->_line))
	{
		this->_line_nb++;
		tmp_status = this->input_is_good_line();
		if (tmp_status == ERR_INPUT_WRONG_LINE)
			err(input_file, ": wrong line, at", this->_line_nb);
		if (tmp_status == ERR_INPUT_WRONG_DATE_LINE)
			err(input_file, ": wrong date, at", this->_line_nb);
		if (tmp_status == ERR_INPUT_WRONG_VALUE_LINE)
			err(input_file, ": wrong value, at", this->_line_nb);
		if (tmp_status == ERR_INPUT_NEGATIVE_VALUE)
			err(input_file, ": value cannot be negative, at", this->_line_nb);
	}
}

bool BitcoinExchange::input_is_good_first_line(void)
{
	this->_line = trim(this->_line);
	return (this->_line == "date | value");
}

int BitcoinExchange::input_is_good_line(void)
{
	std::string	tmp_line = trim(this->_line);
	std::string	date;
	std::string	value;
	double		d_value;
	int			tmp_line_size = (int)tmp_line.size();

	for(int i = 0; i < tmp_line_size; i++){
		if(tmp_line[i] != '|')
			date += tmp_line[i];
		else
			break ;
	}
	if (date.size() == tmp_line.size())
		return (ERR_INPUT_WRONG_LINE);
	value = tmp_line.substr(date.size()+1, tmp_line.size() - date.size());
	date = trim(date);
	value = trim(value);
	if (!this->parse_date(date))
		return (ERR_INPUT_WRONG_DATE_LINE);
	if (!this->input_is_good_value(value))
		return (ERR_INPUT_WRONG_VALUE_LINE);
	d_value = std::strtod(value.c_str(), NULL);
	if (d_value < 0)
		return (ERR_INPUT_NEGATIVE_VALUE);
	this->report(date, d_value);
	return (0);
}

bool BitcoinExchange::input_is_good_value(std::string value)
{
	return (is_int(value) || is_decimal(value));
}

void BitcoinExchange::report(std::string date, double value)
{
	double calculated_value = this->find_closest_date(date) * value;

	if (value <= BTC_MAX_VALUE)
		std::cout	<< date << " ⇉ " << value << " → "
					<< calculated_value << std::endl;
	else
		std::cout << "Error: input value too high" << std::endl;
}

double	BitcoinExchange::find_closest_date(std::string date)
{
	std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator itb = this->_data.begin();

	it = this->_data.lower_bound(date);
	if (it->first != date && it != itb)
		it--;
	return (it->second);
}
