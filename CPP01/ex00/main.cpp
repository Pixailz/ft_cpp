/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:10:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 09:56:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*useless_zombie;

	randomChump("Joy");
	std::cout << std::endl;
	useless_zombie = newZombie("Brainless");
	useless_zombie->announce();
	delete(useless_zombie);
	return (0);
}
