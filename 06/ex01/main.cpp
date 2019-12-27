/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:28:09 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 18:58:53 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "test " << i << ": " << '\n';
		void *raw = serialize();
		Data *dt = deserialize(raw);

		std::cout << "\tstr1: " << dt->s1 << '\n';
		std::cout << "\tn:    " << dt->n << '\n';
		std::cout << "\tstr2: " << dt->s2 << std::endl;

		delete static_cast<char*>(raw);
		delete dt;
	}

	return (0);
}
