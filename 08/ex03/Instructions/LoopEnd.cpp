/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopEnd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:32 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:12:35 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LoopEnd.hpp"

LoopEnd::LoopEnd(Program &mindOpen):
	Instruction(mindOpen)
{
}

LoopEnd::LoopEnd(LoopEnd const &other):
	Instruction(other)
{
}

LoopEnd::~LoopEnd()
{
}

LoopEnd &LoopEnd::operator=(LoopEnd const &other)
{
	(void)other;
	return (*this);
}

void LoopEnd::execute(void)
{
	if (this->mo.getPtrData() != 0)
		this->mo.moveToPreviousLoop();
}

int LoopEnd::getType(void) const
{
	return (7);
}
