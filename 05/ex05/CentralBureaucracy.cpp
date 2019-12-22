/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 19:27:13 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 20:05:01 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy():
	bureaucratCount(0), inQueue(0), queue(nullptr)
{
	for (int i = 0; i < 20; i++)
		this->offices[i].setIntern(this->interns[i]);
}

CentralBureaucracy::~CentralBureaucracy()
{
	if (this->queue)
		delete[] this->queue;
}

void CentralBureaucracy::feed(Bureaucrat const &bureaucrat)
{
	if (this->bureaucratCount == 40)
		throw CentralBureaucracy::BureaucratyFullException();
	int office = this->bureaucratCount / 2;
	int post = (this->bureaucratCount % 1) == 0;
	if (post == 0)
		this->offices[office].setSigner(bureaucrat);
	else
		this->offices[office].setExecutor(bureaucrat);
}

void CentralBureaucracy::queueUp(std::string const &target)
{
	if (this->inQueue == 0)
	{
		this->queue = new std::string[1];
		this->queue[0] = target;
		this->inQueue = 1;
	}
	else
	{
		std::string *cpy = new std::string[this->inQueue + 1];
		for (int i = 0; i < this->inQueue; i++)
			cpy[i] = this->queue[i];
		delete[] this->queue;
		this->queue = cpy;
		this->queue[this->inQueue] = target;
		this->inQueue++;
	}
}

void CentralBureaucracy::doBureaucracy(void)
{
	int action;
	static std::string actions[3] = {
		"Presidential Pardon",
		"Robotomy Request",
		"Shrubbery Creation"
	};

	for (int i = 0; i < this->inQueue; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			try
			{
				action = (rand() % 3);
				this->offices[j].doBureaucracy(actions[action], this->queue[i]);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	delete[] this->queue;
	this->queue = nullptr;
	this->inQueue = 0;
}

CentralBureaucracy &operator<<(CentralBureaucracy &bureau, Bureaucrat const &bureaucrat)
{
	bureau.feed(bureaucrat);
	return (bureau);
}

CentralBureaucracy &operator<<(CentralBureaucracy &bureau, std::string const &target)
{
	bureau.queueUp(target);
	return (bureau);
}