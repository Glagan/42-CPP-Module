/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:26:21 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 20:00:45 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid():
	name("Asteroid")
{
}

KoalaSteroid::KoalaSteroid(std::string const &name):
	name(name)
{
}

KoalaSteroid::KoalaSteroid(KoalaSteroid const &other):
	name(other.name)
{
}


KoalaSteroid::~KoalaSteroid()
{
}

KoalaSteroid &KoalaSteroid::operator=(KoalaSteroid const &other)
{
	this->name = other.name;
	return (*this);
}

std::string KoalaSteroid::getName(void) const
{
	return (this->name);
}

std::string KoalaSteroid::beMined(DeepCoreMiner *laser) const
{
	(void)laser;
	return (std::string("Dragonite"));
}

std::string KoalaSteroid::beMined(StripMiner *laser) const
{
	(void)laser;
	return (std::string("Flavium"));
}
