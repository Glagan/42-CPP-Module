/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:19:16 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 16:52:39 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()
{
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &other)
{
	(void)other;
}

DeepCoreMiner::~DeepCoreMiner()
{
}

DeepCoreMiner &DeepCoreMiner::operator=(DeepCoreMiner const &other)
{
	(void)other;
	return (*this);
}

void DeepCoreMiner::mine(IAsteroid *asteroid)
{
	if (asteroid == nullptr)
		return ;
	std::cout << "* mining deep ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}
