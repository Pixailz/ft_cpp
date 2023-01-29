/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:26:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 09:49:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name.clear();
	// std::cout << "Zombie class created\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	// std::cout << "Zombie class created with name (" << name << ")\n";
}

Zombie::~Zombie(void) { }
// {
// 	std::cout << "Zombie class destructed\n";
// }

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
