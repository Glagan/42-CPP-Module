/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:39:30 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 18:43:52 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
# define INPUT_HPP

# include "Program.hpp"
# include "Instruction.hpp"

class Input: public Instruction
{
private:
	Input();
public:
	Input(Program &mindOpen);
	Input(Input const &other);
	virtual ~Input();

	Input &operator=(Input const &other);

	void execute(void);
	int getType(void) const;
};

#endif
