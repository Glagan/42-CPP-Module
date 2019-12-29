/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Incr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:03 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:48 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCR_HPP
# define INCR_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class Incr: public Instruction
{
private:
	Incr();
public:
	Incr(Program &mindOpen);
	Incr(Incr const &other);
	virtual ~Incr();

	Incr &operator=(Incr const &other);

	void execute(void);
	int getType(void) const;
};

#endif
