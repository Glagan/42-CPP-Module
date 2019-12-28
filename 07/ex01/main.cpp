/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:06:16 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 15:16:48 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Number.hpp"
#include "iter.hpp"
#include "iter.cpp"

template<typename T>
void display(T value)
{
	std::cout << value << " ";
}

int main(void)
{
	int intR[5] = { 0, 1, 2, 3, 4 };
	iter(intR, 5, &display); std::cout << std::endl;

	float floatR[5] = { 0.0f, 1.1f, 2.2f, 3.3f, 4.4f };
	iter(floatR, 5, &display); std::cout << std::endl;

	double doubleR[5] = { 0.00, 1.11, 2.22, 3.33, 4.44 };
	iter(doubleR, 5, &display); std::cout << std::endl;

	bool boolR[2] = { false, true };
	iter(boolR, 2, &display); std::cout << std::endl;

	std::string stringR[5] = { "phrase 1", "phrase 2", "templates", "are", "fun" };
	iter(stringR, 5, &display); std::cout << std::endl;
	iter(stringR, 2, &display); std::cout << std::endl;
	iter(stringR, 0, &display); std::cout << std::endl;

	Number numberR[5] = { 0, 5, 1, 2, 3 };
	iter(numberR, 5, &display); std::cout << std::endl;

	return (0);
}
