/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:12:49 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:29:21 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int size):
	type(std::string()), size(size)
{
	if (size > 0)
	{
		this->zombies = new Zombie[size];
		for (int i = 0; i < size; i++)
			this->zombies[i].setCharacteristics(this->type, Zombie::randomName(10));
	}
	else
		std::cout << "# Not enough zombies !" << std::endl;
}

ZombieHorde::ZombieHorde(std::string const &type, int size):
	type(type), size(size)
{
	if (size > 0)
	{
		this->zombies = new Zombie[size];
		for (int i = 0; i < size; i++)
			this->zombies[i].setCharacteristics(this->type, Zombie::randomName(10));
	}
	else
		std::cout << "# Not enough zombies !" << std::endl;
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "Horde " << this->type << " is being destroyed !" << std::endl;
	delete[] this->zombies;
}

void ZombieHorde::announce(void)
{
	for (int i = 0; i < this->size; i++)
		this->zombies[i].announce();
}
