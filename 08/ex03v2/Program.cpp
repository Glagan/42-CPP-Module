/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:22:12 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 15:39:30 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"

Program::Program(int stackSize):
	curr(0), pointer(0), stackSize(stackSize)
{
	this->stack.resize(this->stackSize, 0);
}

Program::Program(Program const &other):
	curr(other.curr), pointer(other.pointer), stackSize(other.stackSize)
{
	this->instructions.clear();
	this->loops.clear();
	this->stack.clear();
	this->stack.resize(other.stackSize, 0);
	for (int i = 0; i < other.stackSize; i++)
		this->stack[i] = other.stack[i];
	this->instructions = other.instructions;
	this->loops = other.loops;
}

Program::~Program()
{
	this->instructions.clear();
	this->loops.clear();
	this->stack.clear();
}

Program &Program::operator=(Program const &other)
{
	this->instructions.clear();
	this->loops.clear();
	this->stack.clear();
	this->stack.resize(other.stackSize, 0);
	for (int i = 0; i < other.stackSize; i++)
		this->stack[i] = other.stack[i];
	this->curr = other.curr;
	this->pointer = other.pointer;
	this->stackSize = other.stackSize;
	this->instructions = other.instructions;
	this->loops = other.loops;
	return (*this);
}

void Program::addInstruction(int instruction)
{
	this->instructions.push_back(instruction);
}

void Program::setLoops(int instr)
{
	size_t length = this->instructions.size();

	this->loops.reserve(instr);
	for (size_t i = 0; i < length; i++)
	{
		if (this->instructions[i] == LoopStart)
			this->addLoop(i, this->moveToNextLoop(i, length));
	}
}

void Program::addLoop(int start, int end)
{
	this->loops[start] = end;
	this->loops[end] = start;
}

int Program::moveToNextLoop(int start, int size)
{
	int sub = 0;

	start++;
	while (start < size && sub >= 0)
	{
		if (this->instructions[start] == LoopStart)
			sub++;
		else if (this->instructions[start] == LoopEnd)
			sub--;
		start++;
	}
	return (--start);
}

void Program::executeInstruction(int instruction)
{
	switch (instruction)
	{
	case IncrData:
		this->stack[this->pointer]++;
		break;
	case IncrPtr:
		this->pointer++;
		break;
	case DecrData:
		this->stack[this->pointer]--;
		break;
	case DecrPtr:
		this->pointer--;
		break;
	case Input:
		std::cin >> this->stack[this->pointer];
		break;
	case Output:
		std::cout << this->stack[this->pointer];
		break;
	case LoopStart:
		if (this->stack[this->pointer] == 0)
			this->curr = this->loops[this->curr];
		break;
	case LoopEnd:
		if (this->stack[this->pointer] != 0)
			this->curr = this->loops[this->curr];
		break;
	}
}

void Program::execute(void)
{
	size_t length = this->instructions.size();

	for (this->curr = 0; this->curr < length; this->curr++)
		this->executeInstruction(this->instructions[this->curr]);
}
