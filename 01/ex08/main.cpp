/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:27:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 19:44:19 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void)
{
	Human h;

	h.action("meleeAttack", "You");
	h.action("rangedAttack", "You");
	h.action("intimidatingShout", "YOU");
	//h.action("no", "YOU");
	return (0);
}
