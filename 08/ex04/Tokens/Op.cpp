/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Op.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 17:46:34 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Op.hpp"

Op::Op(char op):
	op(op)
{
}

Op::Op(Op const &other):
	op(other.op)
{
}

Op::~Op()
{
}

Op &Op::operator=(Op const &other)
{
	this->op = other.op;
	return (*this);
}

int Op::getType(void) const
{
	return (1);
}

char Op::getOp(void) const
{
	return (this->op);
}

void Op::display(void) const
{
	std::cout << "Op(" << this->op << ")";
}
