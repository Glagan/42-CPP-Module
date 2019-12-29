/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Output.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:42 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:47:32 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Output.hpp"

Output::Output(Program &mindOpen):
	Instruction(mindOpen)
{
}

Output::Output(Output const &other):
	Instruction(other)
{
}

Output::~Output()
{
}

Output &Output::operator=(Output const &other)
{
	(void)other;
	return (*this);
}

void Output::execute(void)
{
	std::cout << this->mo.getPtrData();
}

int Output::getType(void) const
{
	return (5);
}
