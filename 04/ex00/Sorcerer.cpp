/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:28:17 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 17:08:22 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title):
	name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &other):
	name(other.name), title(other.title)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title\
			<< ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &other)
{
	this->name = other.name;
	this->title = other.title;
	return (*this);
}

std::string const &Sorcerer::getName(void) const
{
	return (this->name);
}

std::string const &Sorcerer::getTitle(void) const
{
	return (this->title);
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &sorcerer)
{
	out << "I am " << sorcerer.getName() << ", "
		<< sorcerer.getTitle() << ", and I like ponies !" << std::endl;
	return (out);
}