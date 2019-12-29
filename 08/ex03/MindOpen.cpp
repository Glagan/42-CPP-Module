/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:58:21 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:07:45 by ncolomer         ###   ########.fr       */
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
	int countStart = 0;

	this->moriginal = str;
	for (size_t i = 0; i < length; i++)
	{
		switch (str[i])
		{
		case '>':
			this->program.addInstruction(new IncrPtr(this->program));
			break;
		case '<':
			this->program.addInstruction(new DecrPtr(this->program));
			break;
		case '+':
			this->program.addInstruction(new Incr(this->program));
			break;
		case '-':
			this->program.addInstruction(new Decr(this->program));
			break;
		case '.':
			this->program.addInstruction(new Output(this->program));
			break;
		case ',':
			this->program.addInstruction(new Input(this->program));
			break;
		case '[':
			this->program.addInstruction(new LoopStart(this->program));
			countStart++;
			break;
		case ']':
			this->program.addInstruction(new LoopEnd(this->program));
			countStart--;
			break;
		}
	}
	if (countStart != 0)
		return (false);
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
	try
	{
		this->program.execute();
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
	}
}
