/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Postfix.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:37:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 18:27:55 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Postfix.hpp"

Postfix::Postfix():
	acc(0)
{
}

Postfix::Postfix(std::string const &expression):
	acc(0)
{
	this->setExpression(expression);
}

Postfix::Postfix(Postfix const &other)
{
	this->acc = other.acc;
	this->original = other.original;
	this->simple = other.simple;
	this->tokens.clear();
	this->tokens = other.tokens;
	this->postfix.clear();
	this->postfix = other.postfix;
}

Postfix::~Postfix()
{
	this->tokens.clear();
	this->postfix.clear();
}

Postfix &Postfix::operator=(Postfix const &other)
{
	this->acc = other.acc;
	this->original = other.original;
	this->simple = other.simple;
	this->tokens.clear();
	this->tokens = other.tokens;
	this->postfix.clear();
	this->postfix = other.postfix;
	return (*this);
}

bool Postfix::isOperand(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void Postfix::setExpression(std::string const &expression)
{
	this->original = expression;
	this->simplify();
	if (this->simple.find_first_not_of("0123456789+-*/") != std::string::npos)
		throw "invalid character.";
}

void Postfix::simplify(void)
{
	size_t length = this->original.length();
	std::stringstream ss;

	for (size_t i = 0; i < length; i++)
		if (this->original[i] != ' ')
			ss << this->original[i];
	this->simple = ss.str();
}

void Postfix::tokenize(void)
{
	size_t length = this->simple.length();

	for (size_t i = 0; i < length; i++)
	{
		if (std::isdigit(this->simple[i]))
		{
			std::stringstream ss;
			while (std::isdigit(this->simple[i]))
				ss << this->simple[i++];
			i--;
			this->tokens.push_back(new Num(std::stoi(ss.str())));
		}
		else if (this->simple[i] == '(')
			this->tokens.push_back(new ParOpen());
		else if (this->simple[i] == ')')
			this->tokens.push_back(new ParClose());
		else if (this->isOperand(this->simple[i]))
			this->tokens.push_back(new Op(this->simple[i]));
	}
}

void Postfix::displayTokens(void) const
{
	std::deque<Token*>::const_iterator it = this->tokens.begin();
	std::deque<Token*>::const_iterator ite = this->tokens.end();

	std::cout << "Tokens : ";
	for ( ; it != ite; it++)
	{
		(*it)->display();
		if (it + 1 == ite)
			std::cout << std::endl;
		else
			std::cout << ' ';
	}
}

/**
 * Add every Number to stack
 * Add every operand to stack
 * When seeing closing parenthesis unload operand stack up to the last opened parenthesis,
 * also unload the operand up to the last opened parenthesis.
 **/
void Postfix::polish(void)
{
	std::deque<Token*>::const_iterator it = this->tokens.begin();
	std::deque<Token*>::const_iterator ite = this->tokens.end();
	std::deque<Num*> numStack;
	std::deque<Op*> opStack;

	for ( ; it != ite; it++)
	{
		if ((*it)->getType() == 0)
			numStack.push_back(static_cast<Num*>(*it));
		else if ((*it)->getType() == 1)
			numStack.push_back(static_cast<Num*>(*it));
		else if ((*it)->getType() == 2)
		{

		}
		else if ((*it)->getType() == 3)
		{

		}
	}
}

void Postfix::displayPostfix(void) const
{
	std::deque<Token*>::const_iterator it = this->postfix.begin();
	std::deque<Token*>::const_iterator ite = this->postfix.end();

	std::cout << "Postfix : ";
	for ( ; it != ite; it++)
	{
		(*it)->display();
		if (it + 1 == ite)
			std::cout << std::endl;
		else
			std::cout << ' ';
	}
}

int Postfix::execute(int a, char op, int b) const
{
	switch (op)
	{
	case '+':
		std::cout << "Add\t| ";
		return (a + b);
	case '-':
		std::cout << "Substract\t| ";
		return (a - b);
	case '*':
		std::cout << "Multiply\t| ";
		return (a * b);
	case '/':
		std::cout << "Divide\t| ";
		return (a / b);
	}
	return (a);
}

void Postfix::displayStack(std::deque<int> const &stack) const
{
	std::deque<int>::const_iterator it = stack.begin();
	std::deque<int>::const_iterator ite = stack.end();

	std::cout << "ST ";
	for ( ; it != ite; it++)
	{
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << ' ';
	}
	std::cout << "]" << std::endl;
}

void Postfix::calculate(void)
{
	std::deque<int> stack;
	std::deque<Token*>::iterator it = this->postfix.begin();
	std::deque<Token*>::iterator ite = this->postfix.end();

	for ( ; it != ite; it++)
	{
		if ((*it)->getType() == 0)
		{
			stack.push_back(static_cast<Num*>(*it)->getValue());
			std::cout << "I ";
			(*it)->display();
			std::cout << " | OP Push\t| ";
			this->displayStack(stack);
		}
		else if ((*it)->getType() == 1)
		{
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			std::cout << "I ";
			(*it)->display();
			std::cout << " | OP ";
			stack.push_back(this->execute(b, static_cast<Op*>(*it)->getOp(), a));
			this->displayStack(stack);
		}
	}
	std::cout << "Result : " << stack.back() << std::endl;
	stack.pop_back();
}
