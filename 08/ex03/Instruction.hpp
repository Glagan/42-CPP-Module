/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:58:23 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:50:13 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

class Program;
# include "Program.hpp"

class Instruction
{
private:
	Instruction();
protected:
	Program &mo;
public:
	Instruction(Program &mo);
	Instruction(Instruction const &other);
	virtual ~Instruction();

	Instruction &operator=(Instruction const &other);

	virtual void execute(void) = 0;
	virtual int getType(void) const = 0;
};

#endif
