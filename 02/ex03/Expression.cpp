/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:28:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 16:06:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Expression.hpp"

Expression::Expression():
	acc(0), str(std::string()), expr(std::string())
{
}

Expression::Expression(std::string const &str):
	acc(0)
{
	this->setExpression(str);
}

Expression::Expression(Expression const &other):
	acc(other.acc), str(other.str), expr(other.expr)
{
}

Expression::~Expression()
{
}

Expression &Expression::operator=(Expression const &other)
{
	this->acc = other.acc;
	this->str = other.str;
	this->expr = other.expr;
	return (*this);
}

bool Expression::isOperand(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void Expression::simplify(void)
{
	std::stringstream ss;
	size_t length;
	size_t j;
	size_t stack;

	length = this->str.length();
	for (size_t i = 0; i < length; i++)
	{
		if (this->str[i] == ')')
			throw "invalid bracket closing.";
		else if (this->str[i] == '(')
		{
			std::string tmp(ss.str());
			if (tmp.length() > 0
				&& !Expression::isOperand(tmp[tmp.length() - 1]))
				throw "missing operand.";
			stack = 0;
			for (j = i + 1; j < length; j++)
			{
				if (this->str[j] == '(')
					stack++;
				else if (this->str[j] == ')')
				{
					if (stack == 0)
						break ;
					else
						stack--;
				}
			}
			if (stack > 0 || i + 1 == j || this->str[j] != ')')
				throw "unclosed bracket.";
			ss << (Expression(this->str.substr(i + 1, j - i - 1))).calculate();
			i = j;
		}
		else if (this->str[i] != ' ')
			ss << this->str[i];
	}
	this->expr = ss.str();
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
	if (!operand && str.length() == 0)
		throw "missing value.";
	else if (str.length() == 0)
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

Fixed Expression::calculate(void)
{
	Fixed acc;
	std::stringstream ss;
	size_t length;
	char operand;

	length = this->expr.length();
	operand = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (Expression::isOperand(this->expr[i]))
		{
			if (i + 1 >= length)
				throw "invalid operand position.";
			if ((this->expr[i] == '-' || this->expr[i] == '+')
				&& ::isdigit(this->expr[i + 1])
				&& !::isdigit(this->expr[i - 1]))
				ss << this->expr[i];
			else
			{
				Expression::accumulate(acc, operand, ss);
				operand = this->expr[i];
			}
		}
		else
			ss << this->expr[i];
	}
	Expression::accumulate(acc, operand, ss);
	return (acc);
}

std::string &Expression::getExpression(void)
{
	return (this->str);
}

void Expression::setExpression(std::string const &expr)
{
	this->str = expr;
	this->simplify();
	if (this->expr.find_first_not_of("0123456789.+-*/") != std::string::npos)
		throw "invalid character.";
}
