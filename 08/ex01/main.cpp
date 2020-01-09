/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:41:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/09 16:08:28 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "Span.hpp"

void displaySpan(std::string const &name, Span &span)
{
	std::cout << name << ": "
			<< span.shortestSpan() << ", "
			<< span.longestSpan() << std::endl;
}

int main(void)
{
	srand(time(NULL));

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	displaySpan("Simple", sp);

	Span spcopy = sp;
	displaySpan("Simple (Copy)", spcopy);

	Span spfifty = Span(50);
	for (int i = 0; i < 50; i++)
		spfifty.addNumber(i);
	displaySpan("0 to 49 (included)", spfifty);

	Span spcopyc = Span(spfifty);
	displaySpan("0 to 49 (included, Copy Constructor)", spcopyc);

	Span sphard = Span(50);
	sphard.addNumber(2);
	sphard.addNumber(5);
	sphard.addNumber(6);
	sphard.addNumber(12);
	sphard.addNumber(7);
	sphard.addNumber(9);
	sphard.addNumber(54);
	displaySpan("[2, 5, 6, 12, 7, 9, 54] -> [1, 52]", sphard);

	Span spzeroone = Span(2);
	spzeroone.addNumber(0);
	spzeroone.addNumber(1);
	displaySpan("0 and one", spzeroone);

	Span sphundred = Span(100);
	for (int i = 0; i < 100; i++)
		sphundred.addNumber(i - 50);
	displaySpan("-50 to 49 (included)", sphundred);

	Span spallsame = Span(100);
	for (int i = 0; i < 100; i++)
		spallsame.addNumber(1);
	displaySpan("All the same", spallsame);

	for (int i = 0; i < 20; i++)
	{
		std::vector<int> tmp;
		Span sprandom = Span(100000);
		for (int i = 0; i < 100000; i++)
			tmp.push_back((rand() % 100000) - 50000);
		sprandom.addNumber(tmp.begin(), tmp.end());
		displaySpan("Random", sprandom);
	}

	std::cout << "---" << std::endl;

	Span spexception(3);
	try
	{
		displaySpan("Exception", spexception);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	spexception.addNumber(1);
	try
	{
		displaySpan("Exception", spexception);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	spexception.addNumber(1);
	spexception.addNumber(1);

	try
	{
		spexception.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);

		Span spexception = Span(3);
		spexception.addNumber(lst.begin(), lst.end());
		displaySpan("Exception", spexception);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
