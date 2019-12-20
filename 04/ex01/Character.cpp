/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:46:26 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 16:17:14 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():
	name(std::string()), ap(0), weapon(NULL)
{
}

Character::Character(std::string const &name):
	name(name), ap(40), weapon(NULL)
{
}

Character::Character(Character const &other):
	name(other.name), ap(other.ap), weapon(other.weapon)
{

}

Character::~Character()
{
}

Character &Character::operator=(Character const &other)
{
	this->name = other.name;
	this->ap = other.ap;
	this->weapon = other.weapon;
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

int Character::getAP(void) const
{
	return (this->ap);
}

AWeapon *Character::getWeapon(void) const
{
	return (this->weapon);
}

void Character::recoverAP(void)
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void Character::attack(Enemy *enemy)
{
	if (!this->weapon || !enemy)
		return ;
	if (this->ap < this->weapon->getAPCost())
		return ;
	this->ap -= this->weapon->getAPCost();
	std::cout << this->name << " attacks " << enemy->getType()
			<< " with a " << this->weapon->getName() << std::endl;
	this->weapon->attack();
	enemy->takeDamage(this->weapon->getDamage());
	if (enemy->getHP() == 0)
		delete enemy;
}

std::ostream &operator<<(std::ostream &out, Character const &chara)
{
	out << chara.getName() << " has " << chara.getAP() << " AP and ";
	if (chara.getWeapon())
		out << "wields a " << chara.getWeapon()->getName();
	else
		out << "is unarmed";
	out << std::endl;
	return (out);
}
