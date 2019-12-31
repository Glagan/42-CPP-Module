/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParClose.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:19 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/31 20:08:08 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParClose.hpp"

ParClose::ParClose()
{
}

ParClose::ParClose(ParClose const &other)
{
	(void)other;
}

ParClose::~ParClose()
{
}

ParClose &ParClose::operator=(ParClose const &other)
{
	(void)other;
	return (*this);
}

int ParClose::getType(void) const
{
	return (TokenParClose);
}

void ParClose::display(void) const
{
	std::cout << "ParClose";
}
