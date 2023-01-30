/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:10:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 18:07:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	a_string_variable = std::string("HI THIS IS BRAIN");
	std::string	*a_ptr_variable = &a_string_variable;
	std::string	&a_ref_variable = a_string_variable;

	std::cout << "addresse of a_string_variable : " << &a_string_variable
			  << std::endl;
	std::cout << "addresse of a_ptr_variable : " << &a_ptr_variable
			  << std::endl;
	std::cout << "addresse of a_ref_variable : " << &a_ref_variable
			  << std::endl << std::endl;

	std::cout << "value of a_string_variable : " << a_string_variable
			  << std::endl;
	std::cout << "value of a_ptr_variable : " << a_ptr_variable
			  << std::endl;
	std::cout << "value of a_ref_variable : " << a_ref_variable
			  << std::endl;
	return (0);
}

// g++ -Wall -Werror -Wextra --std=c++98 -g3 main.cpp -o prog && ./prog
