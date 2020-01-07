/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Detector.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:05:20 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/07 11:38:13 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Detector.hpp"

Base *generate(void)
{
	int r = rand() % 100;

	if (r > 66)
		return (new A);
	if (r > 33)
		return (new B);
	return (new C);
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C";
}

void identify_from_reference(Base &p)
{
	identify_from_pointer(&p);
}
