/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:22:10 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:50:43 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_HPP
# define PROGRAM_HPP

# include <iostream>
# include <array>
# include <deque>
class Instruction;

class Program
{
private:
	size_t curr;
	int pointer;
	std::array<char, 30000> stack;
	std::deque<Instruction*> instructions;

	enum InstructionType {
		IncrData,
		IncrPtr,
		DecrData,
		DecrPtr,
		Input,
		Output,
		LoopStart,
		LoopEnd
	};
public:
	Program();
	Program(Program const &other);
	virtual ~Program();

	Program &operator=(Program const &other);

	void addInstruction(Instruction *instruction);

	void incrPtr(void);
	void decrPtr(void);
	void incrData(void);
	void decrData(void);
	void setPtrData(char in);
	char getPtrData(void) const;
	void moveToNextLoop(void);
	void moveToPreviousLoop(void);

	void execute(void);
};

# include "Instruction.hpp"

#endif
