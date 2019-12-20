/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:36:22 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 17:04:54 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const &name):
	ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	std::cout << this->name << ": SUPER CREATING." << std::endl;
	this->level = 1;
	this->hitPoints = this->FragTrap::hitPoints;
	this->maxHitPoints = this->FragTrap::maxHitPoints;
	this->energyPoints = this->NinjaTrap::energyPoints;
	this->maxEnergyPoints = this->NinjaTrap::maxEnergyPoints;
	this->meleeAttackDamage = this->NinjaTrap::meleeAttackDamage;
	this->rangedAttackDamage = this->FragTrap::rangedAttackDamage;
	this->armorDamageReduction = this->FragTrap::armorDamageReduction;
}

SuperTrap::SuperTrap(SuperTrap const &other):
	ClapTrap(other.name), NinjaTrap(name), FragTrap(name)
{
	std::cout << this->name << ": SUPER CREATING." << std::endl;
	ClapTrap::copy(other);
}

SuperTrap::~SuperTrap()
{
	std::cout << this->name << ": SUPER DESTROYING."  << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &other)
{
	ClapTrap::copy(other);
	return (*this);
}
