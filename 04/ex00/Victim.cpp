/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:48:53 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 13:54:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim():
	name(std::string())
{
	std::cout << "Some random victim called " << this->name << " just popped"  << std::endl;
}

Victim::Victim(std::string const &name):
	name(name)
{
	std::cout << "Some random victim called " << this->name << " just popped"  << std::endl;
}

Victim::Victim(Victim const &other):
	name(other.name)
{
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
}

Victim &Victim::operator=(Victim const &other)
{
	this->name = other.name;
	return (*this);
}

std::string const &Victim::getName(void) const
{
	return (this->name);
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Victim const &sorcerer)
{
	out << "I'm " << sorcerer.getName() << " and I like otters !" << std::endl;
	return (out);
}
