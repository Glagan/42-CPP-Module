/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:51:45 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 18:35:35 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name):
	name(name)
{
	std::cout << "ClapTrap " << name << " created." << std::endl;
	this->level = 1;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->meleeAttackDamage = 100;
	this->rangedAttackDamage = 100;
	this->armorDamageReduction = 100;
}

ClapTrap::ClapTrap(ClapTrap const &other):
	name(other.name)
{
	std::cout << "ClapTrap " << name << " created." << std::endl;
	ClapTrap::copy(other);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	ClapTrap::copy(other);
	return (*this);
}

void ClapTrap::copy(ClapTrap const &other)
{
	this->level = other.level;
	this->hitPoints = other.hitPoints;
	this->maxHitPoints = other.maxHitPoints;
	this->energyPoints = other.energyPoints;
	this->maxEnergyPoints = other.maxEnergyPoints;
	this->meleeAttackDamage = other.meleeAttackDamage;
	this->rangedAttackDamage = other.rangedAttackDamage;
	this->armorDamageReduction = other.armorDamageReduction;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "ClapTrap " << this->name << " attacks "
			<< target << " at melee, causing "
			<< this->meleeAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "ClapTrap " << this->name << " attacks "
			<< target << " at range, causing "
			<< this->rangedAttackDamage << " points of damage!" << std::endl;
}

bool ClapTrap::takeDamage(unsigned int amount)
{
	int dealt = amount - this->armorDamageReduction;
	this->hitPoints -= dealt;
	if (this->hitPoints < 0)
	{
		dealt += this->hitPoints;
		this->hitPoints = 0;
	}
	std::cout << this->name << " take "
			<< dealt << " points of damage!" << std::endl;
	return (this->hitPoints == 0);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int healed = amount;
	this->hitPoints += amount;
	if (this->hitPoints > this->maxHitPoints)
	{
		healed -= (this->hitPoints - this->maxHitPoints);
		this->hitPoints = this->maxHitPoints;
	}
	std::cout << this->name << " is repaired for "
			<< healed << "!" << std::endl;
}

std::string const &ClapTrap::getName(void)
{
	return (this->name);
}
