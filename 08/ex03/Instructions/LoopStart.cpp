/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopStart.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:38 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:12:24 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LoopStart.hpp"

LoopStart::LoopStart(Program &mindOpen):
	Instruction(mindOpen)
{
}

LoopStart::LoopStart(LoopStart const &other):
	Instruction(other)
{
}

LoopStart::~LoopStart()
{
}

LoopStart &LoopStart::operator=(LoopStart const &other)
{
	(void)other;
	return (*this);
}

void LoopStart::execute(void)
{
	if (this->mo.getPtrData() == 0)
		this->mo.moveToNextLoop();
}

int LoopStart::getType(void) const
{
	return (6);
}
