/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		BitcoinExchange.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include "main.h"
#include <string>
/*
 * std::get_line()
 * std::atoi()
 */
#include <cstdlib>
/*
 * exit()
 */

#include <stdio.h>
/*
 * strtok()
 */
#include <map>

enum err {
	ERR_NOT_ENOUGHT_ARG = 1,
	ERR_ARG_NOT_GOOD_FILE,
	ERR_DATA_NOT_GOOD_FILE,

	ERR_DATA_WRONG_FIRST_LINE,
	ERR_DATA_WRONG_LINE,
	ERR_DATA_WRONG_DATE_LINE,
	ERR_DATA_WRONG_VALUE_LINE,

	ERR_INPUT_WRONG_FIRST_LINE,
	ERR_INPUT_WRONG_LINE,
	ERR_INPUT_WRONG_DATE_LINE,
	ERR_INPUT_WRONG_VALUE_LINE,
	ERR_INPUT_NEGATIVE_VALUE,
};

#define DATA_FILE		"data.csv"
#define BTC_MAX_VALUE	1000
#define VALUE_COL		ANSI_ESC "25G"

void	err(std::string msg);
void	err(std::string title, std::string msg);
void	err(std::string title, std::string msg, int nb_line);


class BitcoinExchange
{
	private:
		// VAR
		std::ifstream					_input_file;
		std::ifstream					_data_file;
		std::string						_line;
		int								_line_nb;
		std::map<std::string, double>	_data;

		// OTHER FUNCTION
		BitcoinExchange(void);
		BitcoinExchange	&operator=(const BitcoinExchange &src);
		BitcoinExchange(const BitcoinExchange &copy);

		void	parse_data_file(void);
		void	parse_input_file(std::string input_file);

		bool	parse_date(std::string date);

		bool	data_is_good_first_line(void);
		int		data_is_good_line(void);
		bool	data_is_good_value(std::string value);

		bool	input_is_good_first_line(void);
		int		input_is_good_line(void);
		bool	input_is_good_value(std::string value);

		void	report(std::string date, double value);
		double	find_closest_date(std::string date);
	public:
		// CONSTRUCTOR
		BitcoinExchange(std::string input_file);

		// DESTRUCTOR
		~BitcoinExchange(void);

		// OPERATOR

		// EXCEPTION

		// SETTER

		// GETTER

		// OTHER

};

void debug(std::string msg);

#endif // BITCOINEXCHANGE_CLASS
