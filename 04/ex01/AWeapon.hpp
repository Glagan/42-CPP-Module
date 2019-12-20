/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:00:35 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 16:37:11 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
protected:
	AWeapon();

	std::string name;
	int apCost;
	int damage;
public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &other);
	virtual ~AWeapon();

	AWeapon &operator=(AWeapon const &other);

	std::string const &getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;

	virtual void attack() const = 0;
};

#endif
