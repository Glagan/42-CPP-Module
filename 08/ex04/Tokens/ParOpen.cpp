/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParOpen.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:29 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 17:42:30 by ncolomer         ###   ########.fr       */
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
	return (3);
}

void ParOpen::display(void) const
{
	std::cout << "ParOpen";
}
