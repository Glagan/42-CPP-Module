/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrPtr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:09 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCRPTR_HPP
# define INCRPTR_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class IncrPtr: public Instruction
{
private:
	IncrPtr();
public:
	IncrPtr(Program &mindOpen);
	IncrPtr(IncrPtr const &other);
	virtual ~IncrPtr();

	IncrPtr &operator=(IncrPtr const &other);

	void execute(void);
	int getType(void) const;
};

#endif
