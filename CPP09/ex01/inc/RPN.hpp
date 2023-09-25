/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		RPN.hpp                                | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#ifndef RPN_HPP
# define RPN_HPP

#include "main.h"

#include <stack>
#include <exception>

enum err {
	ERR_ARG = 1,
};

void	debug(std::string msg);
void	err(std::string msg);
void	err(std::string title, std::string msg);
void	err(std::string title, int char_pos);

const std::string AVAILABLE_OPERATOR = "*/+-";

typedef std::stack<int> istack;

class RPN
{
	private:
		// VAR
		std::string		_expr;
		std::stack<int>	_stack;

		// OTHER FUNCTION
		RPN(void);
		RPN(const RPN &copy);

		RPN	&operator=(const RPN &src);

		void process_number(char c);
		void process_operator(char c);

		// EXCEPTION
		class WrongExpression : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class UnexpectedCharAt : public std::exception {
			private:
				int _at;
			public:
				UnexpectedCharAt(int i);
				virtual const char *what() const throw();
		};

	public:
		// CONSTRUCTOR
		RPN(std::string expr);

		// DESTRUCTOR
		~RPN(void);

		// OTHER
		void	calculate(void);
};

#endif // RPN_CLASS
