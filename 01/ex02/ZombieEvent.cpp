/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:32:55 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 18:44:20 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	this->type = "";
}

ZombieEvent::~ZombieEvent()
{
}

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(this->type, name));
}

Zombie	*ZombieEvent::randomChump(void)
{
	std::string	name;
	Zombie		*zombie;

	zombie = new Zombie(this->type, Zombie::randomName(10));
	zombie->advert();
	return (zombie);
}