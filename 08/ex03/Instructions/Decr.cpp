/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Decr.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:38:56 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:52:12 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Decr.hpp"

Decr::Decr(Program &mindOpen):
	Instruction(mindOpen)
{
}

Decr::Decr(Decr const &other):
	Instruction(other)
{
}

Decr::~Decr()
{
}

Decr &Decr::operator=(Decr const &other)
{
	(void)other;
	return (*this);
}

void Decr::execute(void)
{
	this->mo.decrData();
}

int Decr::getType(void) const
{
	return (2);
}
