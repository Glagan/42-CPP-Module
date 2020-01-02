/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:41:17 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 14:51:15 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int amount):
	max(amount)
{
}

Span::Span(Span const &other):
	max(other.max)
{
	this->numbers.clear();
	this->numbers = other.numbers;
}

Span::~Span()
{
	this->numbers.clear();
}

const char* Span::FullSpanException::what() const throw()
{
	return "SpanException: Span is already full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "SpanException: not enough numbers in Span";
}

Span &Span::operator=(Span const &other)
{
	this->max = other.max;
	this->numbers.clear();
	this->numbers = other.numbers;
	return (*this);
}

void Span::addNumber(int value)
{
	if (this->numbers.size() == this->max)
		throw Span::FullSpanException();
	this->numbers.push_back(value);
}

int Span::shortestSpan(void) const
{
	unsigned int size = this->numbers.size();
	if (size <= 1)
		throw Span::NotEnoughNumbersException();

	int smallest = *std::min_element(this->numbers.begin(), this->numbers.end());
	int second = this->numbers[0];

	for (unsigned int i = 1; i < this->numbers.size(); i++)
		if (second == smallest
			|| (this->numbers[i] < second && this->numbers[i] > smallest))
			second = this->numbers[i];
	return (std::abs(second - smallest));
}

int Span::longestSpan(void) const
{
	if (this->numbers.size() <= 1)
		throw Span::NotEnoughNumbersException();

	int biggest = *std::max_element(this->numbers.begin(), this->numbers.end());
	int smallest = *std::min_element(this->numbers.begin(), this->numbers.end());
	return (std::abs(biggest - smallest));
}
