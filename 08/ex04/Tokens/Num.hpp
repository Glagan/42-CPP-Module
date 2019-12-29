/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:45:44 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:46:05 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_HPP
# define NUM_HPP

# include "Token.hpp"

class Num: public Token
{
private:
public:
	Num();
	Num(Num const &other);
	virtual ~Num();

	Num &operator=(Num const &other);

};

#endif
