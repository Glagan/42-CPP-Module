/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrPtr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:05 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:47:36 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IncrPtr.hpp"

IncrPtr::IncrPtr(Program &mindOpen):
	Instruction(mindOpen)
{
}

IncrPtr::IncrPtr(IncrPtr const &other):
	Instruction(other)
{
}

IncrPtr::~IncrPtr()
{
}

IncrPtr &IncrPtr::operator=(IncrPtr const &other)
{
	(void)other;
	return (*this);
}

void IncrPtr::execute(void)
{
	this->mo.incrPtr();
}

int IncrPtr::getType(void) const
{
	return (1);
}
