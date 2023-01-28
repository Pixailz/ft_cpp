/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:54:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 15:00:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	is_good_param(std::string user_input)
{
	if (user_input == "ADD" || user_input == "EXIT" || \
		user_input == "SEARCH")
		return (true);
	return (false);
}

void	print_column(std::string content, int length)
{
	bool	is_too_long;
	int		counter;

	is_too_long = content.length > length;
	while (content[counter])
	{
		if (counter == length - 1 && isalnum(content[counter]))
		{
			std::cout << '.';
			break ;
		}
		else
			std::cout << content[counter];
		counter++;
	}
	std::cout << '|';
}
