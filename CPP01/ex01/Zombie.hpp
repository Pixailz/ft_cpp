/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:24:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 10:16:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS
# define ZOMBIE_CLASS

# include <string>
/**
 * std::string
 */
# include <iostream>
/**
 * std::cout
 * std::endl
 */

class Zombie
{
	private:
		std::string	name;

	public:
		// CONSTRUCTOR
		Zombie(void);
		Zombie(std::string name);

		// DESTRUCTOR
		~Zombie(void);

		// OTHERS
		void	set_name(std::string name);
		void	announce(void);

};

Zombie	*zombieHorde(int size, std::string name);
void	zombieHordeDelete(Zombie *horde);

# endif // ZOMBIE_CLASS
