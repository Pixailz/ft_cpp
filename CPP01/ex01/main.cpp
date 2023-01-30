/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:10:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 17:48:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*test;
	int		nb_zombie = 100;

	test = zombieHorde(nb_zombie, "Joy");
	for (int i = 0; i < nb_zombie; i++)
		test[i].announce();
	zombieHordeDelete(test);
	return (0);
}
