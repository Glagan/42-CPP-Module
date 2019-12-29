/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Incr.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:01 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:47:37 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Incr.hpp"

Incr::Incr(Program &mindOpen):
	Instruction(mindOpen)
{
}

Incr::Incr(Incr const &other):
	Instruction(other)
{
}

Incr::~Incr()
{
}

Incr &Incr::operator=(Incr const &other)
{
	(void)other;
	return (*this);
}

void Incr::execute(void)
{
	this->mo.incrData();
}

int Incr::getType(void) const
{
	return (0);
}
