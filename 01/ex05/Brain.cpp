/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:07:35 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/16 14:09:43 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain():
	neurones(1)
{
}

Brain::~Brain()
{
}

int Brain::getNeurones(void) const
{
	return (this->neurones);
}

std::string Brain::identify(void) const
{
	const long adr = (long)this;

	std::stringstream ss;
	ss << "0x" << std::uppercase << std::hex << adr;
	return (ss.str());
}
