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

# include "main.h"

enum	e_type
{
	UNKNOW	= 0,
	CHAR	= 1U << 0,
	INT		= 1U << 1,
	FLOAT	= 1U << 2,
	DOUBLE	= 1U << 3
};

class ScalarConverter
{
	private:
		// VAR
		std::string	_input;
		t_uint8		_input_char;
		int			_input_int;
		float		_input_float;
		double		_input_double;
		t_uint8		_status;
		t_uint8		_type;

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

		// SETTER
		void			set_input(std::string input, bool prot);
		void			set_input_char(t_uint8 input);
		void			set_input_int(int input);
		void			set_input_float(float input);
		void			set_input_double(double input);
		void			set_status(t_uint8 type);
		void			set_type(t_uint8 type);

		// GETTER
		std::string		get_input(void) const;
		std::string		get_input_char_hex(void) const;
		t_uint8			get_input_char(void) const;
		int				get_input_int(void) const;
		float			get_input_float(void) const;
		double			get_input_double(void) const;
		t_uint8			get_status(void) const;
		t_uint8			get_type(void) const;
		std::string		get_type_str(void);

		// OTHER
		void			clear(void);
		void			convert(std::string s);
		bool			is_char(std::string in);
		bool			is_int(std::string in);
		bool			is_float(std::string in);
		bool			is_double(std::string in);
		void			check_type(void);
		void			translate_char(t_uint8 in);
		void			translate_int(std::string in);
		void			translate_float(std::string in);
		void			translate_double(std::string in);
		void			translate(void);
		void			print_char(void);
		void			print_int(void);
		void			print_float(void);
		void			print_double(void);
		void			print(void);
};

#endif // SCALARCONVERTER_CLASS
