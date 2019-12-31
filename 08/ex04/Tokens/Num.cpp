/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:45:41 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/31 20:05:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Num.hpp"

Num::Num(int value):
	value(value)
{
}

Num::Num(Num const &other):
	value(other.value)
{
}

Num::~Num()
{
}

Num &Num::operator=(Num const &other)
{
	this->value = other.value;
	return (*this);
}

int Num::getType(void) const
{
	return (TokenNum);
}

int Num::getValue(void) const
{
	return (this->value);
}

void Num::display(void) const
{
	std::cout << "Num(" << this->value << ")";
}
