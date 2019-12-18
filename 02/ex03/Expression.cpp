/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:28:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/18 13:52:16 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Expression.hpp"

Expression::Expression()
{
}

Expression::~Expression()
{
}

bool Expression::isOperand(char c)
{
	return (c == '+' || c == '-'
			|| c == '*' || c == '/');
}

Fixed &Expression::execute(Fixed &acc, char op, Fixed const &value)
{
	if (!op)
		throw "missing operand.";
	switch (op)
	{
	case '+':
		acc = (acc + value);
		break;
	case '-':
		acc = (acc - value);
		break;
	case '*':
		acc = (acc * value);
		break;
	case '/':
		acc = (acc / value);
		break;
	}
	return (acc);
}

Fixed &Expression::accumulate(Fixed &acc, char operand, std::stringstream &ss)
{
	Fixed value;
	std::string str(ss.str());

	ss.str(std::string());
	ss.clear();
	if (str.length() == 0)
		return (acc);
	try
	{
		value = Fixed(std::stof(str));
	}
	catch(const std::exception& e)
	{
		return (acc);
	}
	if (operand)
		Expression::execute(acc, operand, value);
	else
		acc = value;
	return (acc);
}

Fixed &Expression::calculate(Fixed &acc, std::string const &str)
{
	std::stringstream ss;
	size_t length;
	int j;
	char operand;

	if (str.find_first_not_of(" 0123456789.()+-*/") != std::string::npos)
		throw "invalid expression.";
	operand = 0;
	length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(')
		{
			Expression::accumulate(acc, operand, ss);
			j = length - 1;
			std::cout << "j " << j << std::endl;
			while (j > i && str[j] != ')')
				j++;
			std::cout << "i, j pos of par " << i << "," << j << std::endl;
			std::cout << "j " << j << std::endl;
			if (str[j] != ')')
				throw "invalid expression.";
			Expression::calculate(acc, str.substr(i + 1, j - i));
			i = j;
		}
		else if (str[i] == ' ')
			Expression::accumulate(acc, operand, ss);
		else if (Expression::isOperand(str[i]))
		{
			Expression::accumulate(acc, operand, ss);
			operand = str[i];
		}
		else
			ss << str[i];
	}
	Expression::accumulate(acc, operand, ss);
	return (acc);
}
