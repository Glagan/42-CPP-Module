/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopStart.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:40 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:56 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOPSTART_HPP
# define LOOPSTART_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class LoopStart: public Instruction
{
private:
	LoopStart();
public:
	LoopStart(Program &mindOpen);
	LoopStart(LoopStart const &other);
	virtual ~LoopStart();

	LoopStart &operator=(LoopStart const &other);

	void execute(void);
	int getType(void) const;
};

#endif
