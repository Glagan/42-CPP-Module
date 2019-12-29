/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Output.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:44 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:59 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_HPP
# define OUTPUT_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class Output: public Instruction
{
private:
	Output();
public:
	Output(Program &mindOpen);
	Output(Output const &other);
	virtual ~Output();

	Output &operator=(Output const &other);

	void execute(void);
	int getType(void) const;
};

#endif
