/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:22:12 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 14:35:24 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"

Program::Program():
	curr(0), pointer(0)
{
	for (int i = 0; i < 30000; i++)
		this->stack[i] = 0;
}

Program::Program(Program const &other):
	curr(other.curr), pointer(other.pointer)
{
	this->instructions.clear();
	for (int i = 0; i < 30000; i++)
		this->stack[i] = other.stack[i];
	this->instructions = other.instructions;
}

Program::~Program()
{
	this->instructions.clear();
}

Program &Program::operator=(Program const &other)
{
	this->instructions.clear();
	this->curr = other.curr;
	this->pointer = other.pointer;
	for (int i = 0; i < 30000; i++)
		this->stack[i] = other.stack[i];
	this->instructions = other.instructions;
	return (*this);
}

void Program::addInstruction(Instruction *instruction)
{
	this->instructions.push_back(instruction);
}

void Program::incrPtr(void)
{
	this->pointer++;
}

void Program::decrPtr(void)
{
	this->pointer--;
}

void Program::incrData(void)
{
	this->stack[this->pointer]++;
}

void Program::decrData(void)
{
	this->stack[this->pointer]--;
}

void Program::setPtrData(char in)
{
	this->stack[this->pointer] = in;
}

char Program::getPtrData(void) const
{
	return (this->stack[this->pointer]);
}

void Program::moveToNextLoop(void)
{
	int sub = 0;

	this->curr++;
	while (this->curr < this->instructions.size() && sub >= 0)
	{
		if (this->instructions[this->curr]->getType() == LoopStart)
			sub++;
		else if (this->instructions[this->curr]->getType() == LoopEnd)
			sub--;
		this->curr++;
	}
	this->curr--;
}

void Program::moveToPreviousLoop(void)
{
	int sub = 0;

	this->curr--;
	while (this->curr >= 0 && sub >= 0)
	{
		if (this->instructions[this->curr]->getType() == LoopEnd)
			sub++;
		else if (this->instructions[this->curr]->getType() == LoopStart)
			sub--;
		this->curr--;
	}
	this->curr++;
}

void Program::execute(void)
{
	size_t length = this->instructions.size();

	for (this->curr = 0; this->curr < length; this->curr++)
		this->instructions[this->curr]->execute();
}
