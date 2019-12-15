/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:25:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 19:33:57 by ncolomer         ###   ########.fr       */
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
	int index[255];
	void (Human::* const actions[3])(std::string const &target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	index[(int)'m'] = 0;
	index[(int)'r'] = 1;
	index[(int)'i'] = 2;
	if ("meleeAttack" == action_name
		|| "rangedAttack" == action_name
		|| "intimidatingShout" == action_name)
		(this->*actions[index[(int)action_name[0]]])(target);
	else
		throw "error: Invalid action.";
}
