/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:41:17 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 17:13:35 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

MiningBarge::MiningBarge():
	amount(0)
{
	for (int i = 0; i < 4; i++)
		this->lasers[i] = nullptr;
}

MiningBarge::MiningBarge(MiningBarge const &other):
	amount(0)
{
	for (int i = 0; i < other.amount; i++)
		this->equip(other.lasers[i]);
	for (int i = this->amount; i < 4; i++)
		this->lasers[i] = nullptr;
}

MiningBarge::~MiningBarge()
{
}

MiningBarge &MiningBarge::operator=(MiningBarge const &other)
{
	this->amount = 0;
	for (int i = 0; i < other.amount; i++)
		this->equip(other.lasers[i]);
	for (int i = this->amount; i < 4; i++)
		this->lasers[i] = nullptr;
	return (*this);
}

void MiningBarge::equip(IMiningLaser *laser)
{
	if (this->amount == 4 || laser == nullptr)
		return ;
	for (int i = 0; i < this->amount; i++)
		if (this->lasers[i] == laser)
			return ;
	this->lasers[this->amount++] = laser;
}

void MiningBarge::mine(IAsteroid *asteroid) const
{
	for (int i = 0; i < this->amount; i++)
		this->lasers[i]->mine(asteroid);
}
