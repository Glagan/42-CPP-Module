/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:08:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/08 16:10:45 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec(5, 5);
	for (int i = 0; i < 5; i++)
		vec[i] = i;
	std::vector<int>::iterator foundv = easyfind(vec, 2);
	if (foundv == vec.end())
		std::cout << "cannot find 2 in vector" << std::endl;
	else
		std::cout << "found 2 in vector " << *foundv << std::endl;

	std::deque<int> deque;
	for (int i = 0; i < 5; i++)
		deque.push_back(i);
	std::deque<int>::iterator foundd = easyfind(deque, 3);
	if (foundd == deque.end())
		std::cout << "cannot find 3 in deque" << std::endl;
	else
		std::cout << "found 3 in deque " << *foundd << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i + 42);
	std::list<int>::iterator foundl = easyfind(lst, 42);
	if (foundl == lst.end())
		std::cout << "cannot find 42 in list" << std::endl;
	else
		std::cout << "found 42 in list " << *foundl << std::endl;

	std::set<int> set;
	for (int i = 0; i < 5; i++)
		if (!set.insert(42 + i).second)
			std::cout << "failed to insert " << 42 + i << " in set !" << std::endl;
	std::set<int>::iterator founds = easyfind(set, 42);
	if (founds == set.end())
		std::cout << "cannot find 42 in set" << std::endl;
	else
		std::cout << "found 42 in set " << *founds << std::endl;

	std::multiset<int> multiset;
	for (int i = 0; i < 5; i++)
		multiset.insert(42 + i);
	std::multiset<int>::iterator foundms = easyfind(multiset, 42);
	if (foundms == multiset.end())
		std::cout << "cannot find 42 in multiset" << std::endl;
	else
		std::cout << "found 42 in multiset " << *foundms << std::endl;

	std::map<int, int> map;
	for (int i = 0; i < 5; i++)
		map[i] = i + 42;
	std::map<int, int>::iterator foundm = easyfind(map, 44);
	if (foundm == map.end())
		std::cout << "cannot find 44 in map" << std::endl;
	else
		std::cout << "found 44 in map " << foundm->second << std::endl;

	std::multimap<int, int> multimap;
	for (int i = 0; i < 5; i++)
		multimap.insert(std::pair<int, int>(i, i + 42));
	std::multimap<int, int>::iterator foundmm = easyfind(multimap, 44);
	if (foundmm == multimap.end())
		std::cout << "cannot find 44 in multimap" << std::endl;
	else
		std::cout << "found 44 in multimap " << foundmm->second << std::endl;

	std::cout << "---" << std::endl;

	if (easyfind(vec, 99) == vec.end())
		std::cout << "99 not found in vector" << std::endl;

	if (easyfind(deque, 99) == deque.end())
		std::cout << "99 not found in deque" << std::endl;

	if (easyfind(lst, 99) == lst.end())
		std::cout << "99 not found in list" << std::endl;

	if (easyfind(set, 99) == set.end())
		std::cout << "99 not found in set" << std::endl;

	if (easyfind(multiset, 99) == multiset.end())
		std::cout << "99 not found in multiset" << std::endl;

	if (easyfind(map, 99) == map.end())
		std::cout << "99 not found in map" << std::endl;

	if (easyfind(multimap, 99) == multimap.end())
		std::cout << "99 not found in multimap" << std::endl;

	return (0);
}
