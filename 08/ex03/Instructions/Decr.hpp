/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Decr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:38:58 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:43 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECR_HPP
# define DECR_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class Decr: public Instruction
{
private:
	Decr();
public:
	Decr(Program &mindOpen);
	Decr(Decr const &other);
	virtual ~Decr();

	Decr &operator=(Decr const &other);

	void execute(void);
	int getType(void) const;
};

#endif
