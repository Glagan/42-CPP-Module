/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:25:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:16:00 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack on " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack on " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "SHOUTING ON " << target << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target)
{
	int key;
	void (Human::* const actions[3])(std::string const &target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	key = ("meleeAttack" == action_name) ? 0 :
		("rangedAttack" == action_name) ? 1 :
		("intimidatingShout" == action_name) ? 2
		: throw "Invalid action.";
	(this->*actions[key])(target);
}
