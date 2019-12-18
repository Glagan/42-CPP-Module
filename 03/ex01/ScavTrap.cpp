/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:20:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/18 18:44:18 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string ScavTrap::challenges[NBR_CHALLS] = {
	"Did you try to open me?",
	"A single mag won't be enough!",
	"Let's get this party started!",
	"You call yourself a badass?",
	"Did someone feel something?"
};

ScavTrap::ScavTrap(std::string const &name)
{
	this->name = name;
	std::cout << this->name << ": Locking the door." << std::endl;
	this->initialize();
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name << ": Door breached."  << std::endl;
}

void ScavTrap::initialize(void)
{
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << this->name << " made a ranged attack to "
			<< target << " dealing "
			<< this->rangedAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << this->name << " made a melee attack to "
			<< target << " dealing "
			<< this->meleeAttackDamage << " points of damage!" << std::endl;
}

bool ScavTrap::takeDamage(unsigned int amount)
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

void ScavTrap::beRepaired(unsigned int amount)
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

void ScavTrap::challengeNewcomer(void)
{
	std::cout << this->name << ": ";
	std::cout << ScavTrap::challenges[rand() % NBR_CHALLS] << std::endl;
}
