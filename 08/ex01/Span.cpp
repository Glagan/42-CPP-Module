/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:41:17 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/09 14:40:42 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t amount):
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
	this->numbers.insert(value);
}

size_t Span::shortestSpan(void) const
{
	size_t size = this->numbers.size();
	if (size <= 1)
		throw Span::NotEnoughNumbersException();

	std::multiset<int>::iterator first = this->numbers.begin();
	std::multiset<int>::iterator next = ++this->numbers.begin();
	size_t minDiff = std::abs(*next++ - *first++);
	while (next != this->numbers.end())
	{
		size_t diff = std::abs(*next - *first);
		if (diff < minDiff)
			minDiff = diff;
		first++;
		next++;
	}
	return (minDiff);
}

size_t Span::longestSpan(void) const
{
	if (this->numbers.size() <= 1)
		throw Span::NotEnoughNumbersException();

	int biggest = *std::max_element(this->numbers.begin(), this->numbers.end());
	int smallest = *std::min_element(this->numbers.begin(), this->numbers.end());
	return (std::abs(biggest - smallest));
}
