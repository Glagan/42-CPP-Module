/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrPtr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:23 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:47:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecrPtr.hpp"

DecrPtr::DecrPtr(Program &mindOpen):
	Instruction(mindOpen)
{
}

DecrPtr::DecrPtr(DecrPtr const &other):
	Instruction(other)
{
}

DecrPtr::~DecrPtr()
{
}

DecrPtr &DecrPtr::operator=(DecrPtr const &other)
{
	(void)other;
	return (*this);
}

void DecrPtr::execute(void)
{
	this->mo.decrPtr();
}

int DecrPtr::getType(void) const
{
	return (3);
}
