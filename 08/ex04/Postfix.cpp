/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Postfix.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:37:20 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/10 12:35:12 by ncolomer         ###   ########.fr       */
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
	this->tokens = other.tokens;
	this->postfix = other.postfix;
}

Postfix::~Postfix()
{
	this->tokens.clear();
	this->postfix.clear();
}

const char* Postfix::InvalidNumberException::what() const throw()
{
	return "PostfixException: Number cannot be represented as an int";
}

const char* Postfix::NoExpressionException::what() const throw()
{
	return "PostfixException: No expression to evaluate";
}

const char* Postfix::DivisionByZeroException::what() const throw()
{
	return "PostfixException: Division by zero";
}

const char* Postfix::InvalidExpressionException::what() const throw()
{
	return "PostfixException: Invalid expression";
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
	if (this->simple.length() < 1)
		throw Postfix::NoExpressionException();
}

void Postfix::simplify(void)
{
	static std::string validChars = "0123456789+-*/()";

	this->simple = this->original;
	std::remove(this->simple.begin(), this->simple.end(), ' ');
	if (this->simple.find_first_not_of(validChars) != std::string::npos)
		throw Postfix::InvalidExpressionException();
	int parCount = std::count(this->simple.begin(), this->simple.end(), '(')
				- std::count(this->simple.begin(), this->simple.end(), ')');
	if (parCount != 0
		|| (this->simple.length() > 0 && this->isOperand(this->simple[this->simple.length() - 1])))
		throw Postfix::InvalidExpressionException();
}

void Postfix::tokenize(void)
{
	size_t length = this->simple.length();
	std::stringstream ss;

	for (size_t i = 0; i < length; i++)
	{
		if (std::isdigit(this->simple[i]))
		{
			if (i > 0
				&& !this->isOperand(this->simple[i - 1])
				&& this->simple[i - 1] != '(')
				throw Postfix::InvalidExpressionException();
			while (std::isdigit(this->simple[i]))
				ss << this->simple[i++];
			i--;
			int num;
			ss >> num;
			if (ss.fail())
				throw Postfix::InvalidNumberException();
			this->tokens.push_back(new Num(num));
			ss.str(std::string());
			ss.clear();
		}
		else if (this->simple[i] == '(')
			this->tokens.push_back(new ParOpen());
		else if (this->simple[i] == ')')
			this->tokens.push_back(new ParClose());
		else if (this->isOperand(this->simple[i]))
		{
			if ((this->simple[i] == '-' || this->simple[i] == '+')
				&& (i == 0
				|| this->isOperand(this->simple[i - 1]) || this->simple[i - 1] == '('))
			{
				if ((this->simple[i] == '-' && ss.str() == "-")
					|| (this->simple[i] == '+' && ss.str() == "+"))
					throw Postfix::InvalidExpressionException();
				ss << this->simple[i];
			}
			else
			{
				if (i == 0 || this->isOperand(this->simple[i - 1]))
					throw Postfix::InvalidExpressionException();
				this->tokens.push_back(new Op(this->simple[i]));
			}
		}
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

void Postfix::polish(void)
{
	size_t end = this->tokens.size();
	std::stack<Token*> opStack;

	for (size_t i = 0; i < end; i++)
	{
		if (this->tokens[i]->getType() == Token::TokenNum)
			this->postfix.push_back(this->tokens[i]);
		else if (this->tokens[i]->getType() == Token::TokenOp
				|| this->tokens[i]->getType() == Token::TokenParOpen)
		{
			opStack.push(this->tokens[i]);
		}
		else if (this->tokens[i]->getType() == Token::TokenParClose)
		{
			while (!opStack.empty())
			{
				if (opStack.top()->getType() == Token::TokenParOpen)
				{
					opStack.pop();
					break ;
				}
				this->postfix.push_back(opStack.top());
				opStack.pop();
			}
		}
	}
	while (!opStack.empty())
	{
		this->postfix.push_back(opStack.top());
		opStack.pop();
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
		if (b == 0)
			throw Postfix::DivisionByZeroException();
		return (a / b);
	}
	return (a);
}

void Postfix::displayStack(std::deque<int> const &stack) const
{
	std::deque<int>::const_reverse_iterator it = stack.rbegin();
	std::deque<int>::const_reverse_iterator ite = stack.rend();

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
		if ((*it)->getType() == Token::TokenNum)
		{
			stack.push_back(static_cast<Num*>(*it)->getValue());
			std::cout << "I ";
			(*it)->display();
			std::cout << " | OP Push\t| ";
			this->displayStack(stack);
		}
		else if ((*it)->getType() == Token::TokenOp)
		{
			if (stack.size() < 2)
				throw Postfix::InvalidExpressionException();
			int op2 = stack.back();
			stack.pop_back();
			int op1 = stack.back();
			stack.pop_back();
			std::cout << "I ";
			(*it)->display();
			std::cout << " | OP ";
			stack.push_back(this->execute(op1, static_cast<Op*>(*it)->getOp(), op2));
			this->displayStack(stack);
		}
	}
	if (stack.size() > 1)
		throw Postfix::InvalidExpressionException();
	std::cout << "Result : " << stack.back() << std::endl;
	stack.pop_back();
}
