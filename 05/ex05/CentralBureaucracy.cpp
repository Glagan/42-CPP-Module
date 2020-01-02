/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 19:27:13 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 14:44:04 by ncolomer         ###   ########.fr       */
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

const char* CentralBureaucracy::BureaucratyFullException::what() const throw()
{
	return "CentralBureaucracyException: Every post has already been assigned";
}

void CentralBureaucracy::feed(Bureaucrat const &bureaucrat)
{
	if (this->bureaucratCount == 40)
		throw CentralBureaucracy::BureaucratyFullException();
	int office = this->bureaucratCount / 2;
	int post = (this->bureaucratCount % 2);
	if (post == 0)
		this->offices[office].setSigner(bureaucrat);
	else
		this->offices[office].setExecutor(bureaucrat);
	this->bureaucratCount++;
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
	static std::string actions[3] = {
		"Presidential Pardon",
		"Robotomy Request",
		"Shrubbery Creation"
	};

	for (int i = 0; i < this->inQueue; i++)
	{
		int action = (rand() % 3);
		for (int j = 0; j < 20; j++)
		{
			try
			{
				this->offices[j].doBureaucracy(actions[action], this->queue[i]);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			action = (action + 1) % 3;
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
