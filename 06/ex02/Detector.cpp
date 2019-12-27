/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Detector.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:05:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 19:45:44 by ncolomer         ###   ########.fr       */
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
	/*try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
		return ;
	}
	catch(const std::exception& e) {}*/
}
