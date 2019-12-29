/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:28 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:21:56 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

Input::Input(Program &mindOpen):
	Instruction(mindOpen)
{
}

Input::Input(Input const &other):
	Instruction(other)
{
}

Input::~Input()
{
}

Input &Input::operator=(Input const &other)
{
	(void)other;
	return (*this);
}

void Input::execute(void)
{
	char c;

	std::cin >> c;
	this->mo.setPtrData(c);
}

int Input::getType(void) const
{
	return (4);
}
