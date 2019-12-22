/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:20:26 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:58:23 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap
{
private:
	ScavTrap();

	int hitPoints;
	int maxHitPoints;
	int energyPoints;
	int maxEnergyPoints;
	int level;
	std::string name;
	int meleeAttackDamage;
	int rangedAttackDamage;
	int armorDamageReduction;

	static const int nbrChalls = 5;
	static std::string challenges[ScavTrap::nbrChalls];
public:
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &other);
	virtual ~ScavTrap();

	ScavTrap &operator=(ScavTrap const &other);

	void meleeAttack(std::string const &target);
	void rangedAttack(std::string const &target);
	bool takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void);
};

#endif