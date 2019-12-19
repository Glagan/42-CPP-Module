/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:27:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:16:08 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void)
{
	Human h;

	try
	{
		h.action("meleeAttack", "You");
		h.action("rangedAttack", "You");
		h.action("intimidatingShout", "YOU");
		//h.action("no", "YOU");
	}
	catch(char const *e)
	{
		std::cerr << "human: exception: " << e << std::endl;
	}
	return (0);
}
