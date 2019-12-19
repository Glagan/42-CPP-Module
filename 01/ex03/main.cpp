/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:46:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:02:37 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

#define COUNT		5
#define HORDE_SIZE	5

void fightInNeighborTown(void)
{
	std::cout << "## Creating Horde Red with " << COUNT << " Zombie" << std::endl;
	ZombieHorde red("Red", 10);
	std::cout << "## Creating Horde Blue with " << COUNT << " Zombie" << std::endl;
	ZombieHorde blue("Blue", 10);
	std::cout << "## They fight" << std::endl;
	red.announce();
	blue.announce();
	std::cout << "## Fight is over, nobody won" << std::endl;
	std::cout << "## Hordes will auto-destroy" << std::endl;
}

int main(void)
{
	std::cout << "# Creating Horde Lurker with " << COUNT << " Zombie" << std::endl;
	ZombieHorde lurkers("Lurker", 10);
	std::cout << "# Creating Horde Sniper with " << COUNT << " Zombie" << std::endl;
	ZombieHorde snipers("Sniper", 10);

	std::cout << "# There is a Fight in the neighbor town, again !" << std::endl;
	fightInNeighborTown();
	std::cout << "# Back to the main City" << std::endl;
	std::cout << "# They fight" << std::endl;
	lurkers.announce();
	snipers.announce();
	std::cout << "# Fight is over, nobody won" << std::endl;
	std::cout << "# Hordes will auto-destroy" << std::endl;
	return (0);
}
