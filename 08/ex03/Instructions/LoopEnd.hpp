/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopEnd.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:34 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:54 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOPEND_HPP
# define LOOPEND_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class LoopEnd: public Instruction
{
private:
	LoopEnd();
public:
	LoopEnd(Program &mindOpen);
	LoopEnd(LoopEnd const &other);
	virtual ~LoopEnd();

	LoopEnd &operator=(LoopEnd const &other);

	void execute(void);
	int getType(void) const;
};

#endif
