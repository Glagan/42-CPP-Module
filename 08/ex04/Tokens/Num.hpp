/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:45:44 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 17:41:47 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_HPP
# define NUM_HPP

# include "Token.hpp"

class Num: public Token
{
private:
	Num();

	int value;
public:
	Num(int number);
	Num(Num const &other);
	virtual ~Num();

	Num &operator=(Num const &other);

	int getValue(void) const;
	int getType(void) const;
	void display(void) const;
};

#endif
