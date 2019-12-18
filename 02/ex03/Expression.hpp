/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:28:49 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/18 13:24:13 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPRESSION_HPP
# define EXPRESSION_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Fixed.hpp"

class Expression
{
private:
	static bool isOperand(char c);
	static Fixed &operand(Fixed &acc, char op, std::string const &str);
public:
	Expression();
	~Expression();

	static Fixed &execute(Fixed &acc, char op, Fixed const &value);
	static Fixed &accumulate(Fixed &acc, char operand, std::stringstream &ss);
	static Fixed &calculate(Fixed &acc, std::string const &str);
};

#endif