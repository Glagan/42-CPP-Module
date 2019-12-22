/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:41:24 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:57:03 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class MiningBarge
{
private:
	int amount;
	IMiningLaser *lasers[4];
public:
	MiningBarge();
	MiningBarge(MiningBarge const &other);
	virtual ~MiningBarge();

	MiningBarge &operator=(MiningBarge const &other);

	void equip(IMiningLaser *laser);
	void mine(IAsteroid *asteroid) const;
};

#endif
