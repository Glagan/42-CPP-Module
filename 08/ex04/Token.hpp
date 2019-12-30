/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:43:59 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 17:41:30 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <iostream>

class Token
{
private:
public:
	Token();
	Token(Token const &other);
	virtual ~Token();

	Token &operator=(Token const &other);

	virtual int getType(void) const = 0;
	virtual void display(void) const = 0;
};

#endif
