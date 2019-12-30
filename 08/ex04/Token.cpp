/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:44:06 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 17:57:16 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token()
{
}

Token::Token(Token const &other)
{
	(void)other;
}

Token::~Token()
{
}

Token &Token::operator=(Token const &other)
{
	(void)other;
	return (*this);
}
