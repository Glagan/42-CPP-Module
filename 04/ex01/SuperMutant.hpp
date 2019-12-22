/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:33:34 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:57:30 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy
{
public:
	SuperMutant();
	SuperMutant(SuperMutant const &other);
	virtual ~SuperMutant();

	SuperMutant &operator=(SuperMutant const &other);

	void takeDamage(int damage);
};

#endif
