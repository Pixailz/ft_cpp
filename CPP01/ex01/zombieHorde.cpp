/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:33:18 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 10:18:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	zombieHordeDelete(Zombie *horde)
{
	delete(horde);
}

Zombie	*zombieHorde(int size, std::string name)
{
	Zombie	*new_zombie_horde;

	new_zombie_horde = new Zombie(name)[];
	return (new_zombie_horde);
}
