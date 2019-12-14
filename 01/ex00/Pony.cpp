/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:04:44 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 18:15:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name)
{
	this->name = name;
	std::cout << "Pony \"" << this->name << "\" has been constructed !" << std::endl;
}

Pony::~Pony()
{
	std::cout << "Pony \"" << this->name << "\" is being destructed !" << std::endl;
}

void Pony::cry(void)
{
	std::cout << this->name << ": MY NAME IS " << this->name << std::endl;
}

void Pony::run(void)
{
	std::cout << this->name << ": I'm tired..." << std::endl;
}
