/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:51:53 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/26 16:45:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	ClapTrap();

	std::string name;
	int hitPoints;
	int maxHitPoints;
	int energyPoints;
	int maxEnergyPoints;
	int level;
	int meleeAttackDamage;
	int rangedAttackDamage;
	int armorDamageReduction;

	void copy(ClapTrap const &other);
public:
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &other);
	virtual ~ClapTrap();

	ClapTrap &operator=(ClapTrap const &other);

	virtual void meleeAttack(std::string const &target);
	virtual void rangedAttack(std::string const &target);
	bool takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string const &getName(void);
};

#endif