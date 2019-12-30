/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopReference.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:39:31 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 14:42:40 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LoopReference.hpp"

LoopReference::LoopReference(int entryInt, int exitInt):
	entryInt(entryInt), exitInt(exitInt)
{
}

LoopReference::LoopReference(LoopReference const &other):
	entryInt(other.entryInt), exitInt(other.exitInt)
{
}

LoopReference::~LoopReference()
{
}

LoopReference &LoopReference::operator=(LoopReference const &other)
{
	this->entryInt = other.entryInt;
	this->exitInt = other.exitInt;
	return (*this);
}

int LoopReference::getEntryInt(void) const
{
	return (this->entryInt);
}

int LoopReference::getExitInt(void) const
{
	return (this->exitInt);
}
