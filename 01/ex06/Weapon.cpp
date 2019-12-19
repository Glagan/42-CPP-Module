/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:38:24 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:28:08 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon():
	type("")
{
}

Weapon::Weapon(std::string const &type):
	type(type)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}

std::string const &Weapon::getType(void) const
{
	return (this->type);
}
