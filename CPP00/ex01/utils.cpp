/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:54:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 13:55:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	is_good_param(std::string user_input)
{
	if (user_input == "ADD" || user_input == "EXIT" || \
		user_input == "SEARCH")
		return (true);
	return (false);
}
