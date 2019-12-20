/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:03:42 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 16:15:34 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon():
	name(std::string()), apCost(0), damage(0)
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage):
	name(name), apCost(apcost), damage(damage)
{
}

AWeapon::AWeapon(AWeapon const &other):
	name(other.name), apCost(other.apCost), damage(other.damage)
{
}

AWeapon::~AWeapon()
{
}

AWeapon &AWeapon::operator=(AWeapon const &other)
{
	this->name = other.name;
	this->apCost = other.apCost;
	this->damage = other.damage;
	return (*this);
}

std::string const &AWeapon::getName(void) const
{
	return (this->name);
}

int AWeapon::getAPCost(void) const
{
	return (this->apCost);
}

int AWeapon::getDamage(void) const
{
	return (this->damage);
}
