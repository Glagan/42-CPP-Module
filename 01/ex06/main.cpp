/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:36:37 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 19:44:47 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("Crude Spiked Club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("Some other type of Club");
		bob.attack();
	}
	{
		Weapon club = Weapon("Crude Spiked Club");
		HumanB jim("Jim");

		jim.setWeapon(club);
		jim.attack();
		club.setType("Some other type of Club");
		jim.attack();
	}
	return (0);
}
