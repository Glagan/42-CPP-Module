/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:58:19 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:47:30 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.hpp"

Instruction::Instruction(Program &mindOpen):
	mo(mindOpen)
{
}

Instruction::Instruction(Instruction const &other):
	mo(other.mo)
{
}

Instruction::~Instruction()
{
}

Instruction &Instruction::operator=(Instruction const &other)
{
	(void)other;
	return (*this);
}
