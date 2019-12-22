/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:19:51 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:57:06 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IMiningLaser.hpp"

class StripMiner: public IMiningLaser
{
public:
	StripMiner();
	StripMiner(StripMiner const &other);
	virtual ~StripMiner();

	StripMiner &operator=(StripMiner const &other);

	void mine(IAsteroid *asteroid);
};

#endif
