/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:27:10 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 20:00:28 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog():
	name("Comet")
{
}

AsteroKreog::AsteroKreog(std::string const &name):
	name(name)
{
}

AsteroKreog::AsteroKreog(AsteroKreog const &other):
	name(other.name)
{
}


AsteroKreog::~AsteroKreog()
{
}

AsteroKreog &AsteroKreog::operator=(AsteroKreog const &other)
{
	this->name = other.name;
	return (*this);
}

std::string AsteroKreog::getName(void) const
{
	return (this->name);
}

std::string AsteroKreog::beMined(DeepCoreMiner *laser) const
{
	(void)laser;
	return (std::string("meium"));
}

std::string AsteroKreog::beMined(StripMiner *laser) const
{
	(void)laser;
	return (std::string("Tartarite"));
}
