/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:28:22 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/23 17:11:57 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <random>
#include "CentralBureaucracy.hpp"
#include "Bureaucrat.hpp"

std::string randomName(int length)
{
	static std::string const alphabet = "0123456789abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ";
	static size_t alphabetLength = alphabet.length();
	std::stringstream ss;

	for (int j = 0; j < length; j++)
		ss << alphabet[rand() % alphabetLength];
	return (ss.str());
}

int main(void)
{
	srand(time(NULL));
	CentralBureaucracy cb;
	Bureaucrat *bureaucrats[20];

	for (int i = 0; i < 20; i++)
		bureaucrats[i] = new Bureaucrat(randomName(15), (rand() % 150 + 1));

	try
	{
		cb << *bureaucrats[0] << *bureaucrats[1];
		cb.feed(*bureaucrats[2]);
		cb.feed(*bureaucrats[3]);
		for (int i = 4; i < 20; i++)
			cb << *bureaucrats[i];
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		cb << randomName((rand() % 20) + 1);
		cb.queueUp(randomName((rand() % 20) + 1));
		for (int i = 0; i < (rand() % 50); i++)
			cb << randomName((rand() % 20) + 1);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		cb.doBureaucracy();
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < 20; i++)
		delete bureaucrats[i];

	return (0);
}
