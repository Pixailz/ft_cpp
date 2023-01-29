/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:24:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/29 09:48:43 by brda-sil         ###   ########.fr       */
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

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

# endif // ZOMBIE_CLASS
