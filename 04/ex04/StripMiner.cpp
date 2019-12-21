/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:19:26 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 16:52:57 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

StripMiner::StripMiner()
{
}

StripMiner::StripMiner(StripMiner const &other)
{
	(void)other;
}

StripMiner::~StripMiner()
{
}

StripMiner &StripMiner::operator=(StripMiner const &other)
{
	(void)other;
	return (*this);
}

void StripMiner::mine(IAsteroid *asteroid)
{
	if (asteroid == nullptr)
		return ;
	std::cout << "* strip mining ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}
