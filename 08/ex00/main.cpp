/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:08:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 16:39:20 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i);
	std::cout << easyfind(vec, 2) << std::endl;

	std::array<int, 5> arr;
	for (int i = 0; i < 5; i++)
		arr[i] = i;
	std::cout << easyfind(arr, 3) << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i + 42);
	std::cout << easyfind(lst, 42) << std::endl;

	std::cout << "---" << std::endl;

	try
	{
		std::cout << easyfind(vec, 99) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << easyfind(arr, 99) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << easyfind(lst, 99) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
