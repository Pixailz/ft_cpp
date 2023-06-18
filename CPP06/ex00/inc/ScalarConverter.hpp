/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		ScalarConverter.hpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <main.h>

typedef enum e_type
{
	UNKNOWN	= 0,
	CHAR	= 1U << 0,
	INT		= 1U << 1,
	FLOAT	= 1U << 2,
	DOUBLE	= 1U << 3
}	t_type;

class ScalarConverter
{
	private:
		// VAR

		// OTHER FUNCTION

	public:
		// CONSTRUCTOR
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);

		// DESTRUCTOR
		~ScalarConverter(void);

		// OPERATOR
		ScalarConverter	&operator=(const ScalarConverter &src);

		// EXCEPTION
		class	EmptyInputErr : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class	UnknownTypeConversionErr : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		// OTHER
		static	void		convert(std::string in);
		static	void		convert_char(std::string in);
		static	void		convert_int(std::string in);
		static	void		convert_float(std::string in);
		static	void		convert_double(std::string in);
		static	std::string	convert_hex(unsigned char c);

		static	t_type		get_type(std::string in);
		static	std::string	get_type_str(t_type type);
		static	bool		is_char(std::string in);
		static	bool		is_int(std::string in);
		static	bool		is_float(std::string in);
		static	bool		is_decimal(std::string in);

		static	void		print_char(char c, bool possible);
		static	void		print_int(int i, bool possible);
		static	void		print_float(float f, bool possible);
		static	void		print_float(std::string f);
		static	void		print_double(double d, bool possible);
		static	void		print_double(std::string d);

};

#endif // SCALARCONVERT_CLASS
