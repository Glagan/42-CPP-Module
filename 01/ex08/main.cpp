/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:27:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 18:17:41 by ncolomer         ###   ########.fr       */
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
		std::cerr << "exception: " << e << std::endl;
	}
	return (0);
}
