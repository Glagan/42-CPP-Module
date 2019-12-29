/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrPtr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:21 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:46 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECRPTR_HPP
# define DECRPTR_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class DecrPtr: public Instruction
{
private:
	DecrPtr();
public:
	DecrPtr(Program &mindOpen);
	DecrPtr(DecrPtr const &other);
	virtual ~DecrPtr();

	DecrPtr &operator=(DecrPtr const &other);

	void execute(void);
	int getType(void) const;
};

#endif
