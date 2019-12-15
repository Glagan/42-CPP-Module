/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:04:41 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 19:45:41 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheStack(void)
{
	Pony onTheStack("Stack Man");

	onTheStack.cry();
	onTheStack.run();
}

void ponyOnTheHeap(void)
{
	Pony *onTheHeap;

	onTheHeap = new Pony("Heap Man");
	onTheHeap->run();
	onTheHeap->cry();
	delete onTheHeap;
}

int main(void)
{
	std::cout << "# ponyOnTheStack:" << std::endl;
	ponyOnTheStack();
	std::cout << "# ponyOnTheHeap:" << std::endl;
	ponyOnTheHeap();
	std::cout << "# Done" << std::endl;
	return (0);
}
