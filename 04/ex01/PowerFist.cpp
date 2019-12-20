/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:14:53 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 16:14:56 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist():
	AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &other):
	AWeapon(other)
{
}

PowerFist::~PowerFist()
{
}

PowerFist &PowerFist::operator=(PowerFist const &other)
{
	this->name = other.name;
	this->apCost = other.apCost;
	this->damage = other.damage;
	return (*this);
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
