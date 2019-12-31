/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParOpen.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:29 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/31 20:06:57 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParOpen.hpp"

ParOpen::ParOpen()
{
}

ParOpen::ParOpen(ParOpen const &other)
{
	(void)other;
}

ParOpen::~ParOpen()
{
}

ParOpen &ParOpen::operator=(ParOpen const &other)
{
	(void)other;
	return (*this);
}

int ParOpen::getType(void) const
{
	return (TokenParOpen);
}

void ParOpen::display(void) const
{
	std::cout << "ParOpen";
}
