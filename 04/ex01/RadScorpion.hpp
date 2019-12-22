/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:40:56 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:57:33 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion: public Enemy
{
public:
	RadScorpion();
	RadScorpion(RadScorpion const &other);
	virtual ~RadScorpion();

	RadScorpion &operator=(RadScorpion const &other);

	using Enemy::takeDamage;
};

#endif
