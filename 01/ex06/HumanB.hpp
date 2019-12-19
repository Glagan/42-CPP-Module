/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:37:25 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 19:11:11 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	const Weapon *weapon;
public:
	HumanB(std::string name);
	~HumanB();

	void setWeapon(const Weapon &weapon);
	void attack(void) const;
};

#endif