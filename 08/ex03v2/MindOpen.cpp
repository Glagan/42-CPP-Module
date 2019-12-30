/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:58:21 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 15:12:09 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"

MindOpen::MindOpen():
	moriginal(""), program()
{
}

MindOpen::MindOpen(MindOpen const &other):
	moriginal(other.moriginal), program(other.program)
{
}

MindOpen::~MindOpen()
{
}

MindOpen &MindOpen::operator=(MindOpen const &other)
{
	this->moriginal = other.moriginal;
	this->program = other.program;
	return (*this);
}

bool MindOpen::loadFromString(std::string const &str)
{
	size_t length = str.length();
	int instr = 0;
	int loopCount = 0;

	this->moriginal = str;
	for (size_t i = 0; i < length; i++)
	{
		switch (str[i])
		{
		case '>':
			this->program.addInstruction(Program::IncrPtr);
			instr++;
			break;
		case '<':
			this->program.addInstruction(Program::DecrPtr);
			instr++;
			break;
		case '+':
			this->program.addInstruction(Program::IncrData);
			instr++;
			break;
		case '-':
			this->program.addInstruction(Program::DecrData);
			instr++;
			break;
		case '.':
			this->program.addInstruction(Program::Output);
			instr++;
			break;
		case ',':
			this->program.addInstruction(Program::Input);
			instr++;
			break;
		case '[':
			this->program.addInstruction(Program::LoopStart);
			instr++;
			loopCount++;
			break;
		case ']':
			this->program.addInstruction(Program::LoopEnd);
			instr++;
			loopCount--;
			break;
		}
	}
	if (loopCount != 0)
		return (false);
	this->program.setLoops(instr);
	return (true);
}

bool MindOpen::loadFromFile(std::string const &filename)
{
	std::stringstream ss;
	std::string line;
	std::ifstream infile(filename);

	if (!infile.is_open() || !infile.good())
		return (false);
	while (std::getline(infile, line))
		ss << line;
	if (infile.bad())
	{
		infile.close();
		return (false);
	}
	infile.close();
	return (this->loadFromString(ss.str()));
}

void MindOpen::execute(void)
{
	this->program.execute();
}
