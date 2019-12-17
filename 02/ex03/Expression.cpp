/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:28:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/17 20:08:10 by ncolomer         ###   ########.fr       */
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

Fixed &Expression::operand(Fixed &acc, char op, std::string const &str)
{
	float tmp;

	if (!op)
		throw "error: eval_expr: invalid expression.";
	tmp = std::stof(str);
	switch (op)
	{
	case '+':
		acc = (acc + Fixed(tmp));
		break;
	case '-':
		acc = (acc - Fixed(tmp));
		break;
	case '*':
		acc = (acc * Fixed(tmp));
		break;
	case '/':
		acc = (acc / Fixed(tmp));
		break;
	}
	return (acc);
}

Fixed &Expression::execute(std::string const &str)
{
	Fixed acc;
	bool hasValue;
	float tmp;
	char operand;
	std::stringstream ss;
	size_t length;

	operand = 0;
	hasValue = false;
	length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (std::isalpha(str[i]) || str[i] == '.')
			ss << str[i];
		else if (str[i] == ' ')
		{
			if (hasValue)
			{
				acc = Expression::operand(acc, operand, ss.str());
				operand = 0;
			}
			else
			{
				acc = Fixed(std::stof(ss.str()));
				hasValue = true;
			}
			ss.clear();
		}
		else if (Expression::isOperand(str[i]))
			operand = str[i];
		else
			throw "error: eval_expr: invalid expression.";
	}
	if (hasValue)
	{
		acc = Expression::operand(acc, operand, ss.str());
		operand = 0;
	}
	else
	{
		acc = Fixed(std::stof(ss.str()));
		hasValue = true;
	}
	ss.clear();
	return (acc);
}

Fixed &Expression::calculate(std::string const &str)
{
	Fixed acc;
	std::stringstream ss;
	std::string tmp;
	size_t length;
	int j;

	length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(')
		{
			tmp = ss.str();
			if (tmp.length() > 0)
				acc += Expression::execute(tmp);
			ss.clear();
			j = length - 1;
			while (j > i && str[j] != ')')
				j++;
			if (str[j] != ')')
				throw "error: eval_expr: invalid expression.";
			acc += Expression::calculate(str.substr(i + 1, j - i));
			i = j;
		}
		else
			ss << str[i];
	}
	tmp = ss.str();
	if (tmp.length() > 0)
		acc += Expression::execute(tmp);
	return (acc);
}
