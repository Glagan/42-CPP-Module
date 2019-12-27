/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:20:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 14:24:08 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string ScavTrap::challenges[ScavTrap::nbrChalls] = {
	"Did you try to open me?",
	"A single mag won't be enough!",
	"Let's get this party started!",
	"You call yourself a badass?",
	"Did someone feel something?"
};

ScavTrap::ScavTrap(std::string const &name):
	ClapTrap(name)
{
	std::cout << this->name << ": Locking the door." << std::endl;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &other):
	ClapTrap(other.name)
{
	std::cout << this->name << ": Locking the door." << std::endl;
	ClapTrap::copy(other);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name << ": Door breached."  << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	ClapTrap::copy(other);
	return (*this);
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << this->name << " made a melee attack to "
			<< target << " dealing "
			<< this->meleeAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << this->name << " made a ranged attack to "
			<< target << " dealing "
			<< this->rangedAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
	std::cout << this->name << ": ";
	std::cout << ScavTrap::challenges[rand() % ScavTrap::nbrChalls] << std::endl;
}
