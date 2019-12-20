/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:14:59 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 16:36:58 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
public:
	PowerFist();
	PowerFist(PowerFist const &other);
	~PowerFist();

	PowerFist &operator=(PowerFist const &other);

	void attack(void) const;
};

#endif
